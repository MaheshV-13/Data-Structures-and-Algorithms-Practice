#include <iostream>
using namespace std;

// Define the minimum degree (T)
// Each node can have at most 2*T - 1 keys and at least T - 1 keys
const int T = 3;

// QUESTION 4

// class to create a NODE for the B-tree
class BTreeNode {
public:
    int keys[2 * T - 1];          // Array to store keys
    BTreeNode* children[2 * T];   // Array to store child pointers
    int n;                        // Current number of keys
    bool leaf;                    // True if node is a leaf

    // Constructor: initializes as leaf or not
    BTreeNode(bool isLeaf) {
        leaf = isLeaf;            // Set leaf flag
        n = 0;                    // No keys initially
        for (int i = 0; i < 2 * T; i++)
            children[i] = nullptr; // Initialize all child pointers to null
    }

    // Function to traverse the subtree rooted with this node
    void traverse() {
        for (int i = 0; i < n; i++) {
            // If not a leaf, recursively traverse the left child before printing key
            if (!leaf) children[i]->traverse();
            cout << keys[i] << " "; // Print the current key
        }
        // Traverse the last child (rightmost)
        if (!leaf) children[n]->traverse();
    }

    // Function to search a key in subtree rooted at this node
    BTreeNode* search(int k) {
        int i = 0;
        // Find the first key greater than or equal to k
        while (i < n && k > keys[i]) i++;

        // If found, return this node
        if (i < n && keys[i] == k) return this;

        // If it's a leaf and not found, return null
        if (leaf) return nullptr;

        // Go to appropriate child
        return children[i]->search(k);
    }

    // Forward declarations
    void insertNonFull(int k);            // Insert when node is not full
    void splitChild(int i, BTreeNode* y); // Split full child
    void remove(int k);                   // Remove key from subtree

    // Helpers for remove
    int findKey(int k);                         // Find index of key or child
    void removeFromLeaf(int idx);               // Case 1: remove from leaf
    void removeFromNonLeaf(int idx);            // Case 2: remove from internal
    int getPredecessor(int idx);                // Get predecessor key
    int getSuccessor(int idx);                  // Get successor key
    void fill(int idx);                         // Ensure child has at least T keys
    void borrowFromPrev(int idx);               // Borrow from previous sibling
    void borrowFromNext(int idx);               // Borrow from next sibling
    void merge(int idx);                        // Merge children around a key
};

// class to create the B-tree itself
class BTree {
public:
    BTreeNode* root;  // Pointer to root node

    // Constructor
    BTree() {
        root = nullptr;
    }

    // Function to traverse the tree
    void traverse() {
        if (root) root->traverse();
    }

    // Search for a key
    BTreeNode* search(int k) {
        return (root == nullptr) ? nullptr : root->search(k);
    }

    // Insert key
    void insert(int k);

    // Remove key
    void remove(int k);
};

// QUESTION 5

// Insert a key into the B-tree
void BTree::insert(int k) {
    if (root == nullptr) {
        // If tree is empty, create root node
        root = new BTreeNode(true);
        root->keys[0] = k; // Insert key
        root->n = 1;       // One key now
    } else {
        if (root->n == 2 * T - 1) {
            // If root is full, need to split
            BTreeNode* s = new BTreeNode(false); // New root is not leaf
            s->children[0] = root;               // Old root becomes child
            s->splitChild(0, root);              // Split the old root

            // Insert into appropriate child
            int i = (s->keys[0] < k) ? 1 : 0;
            s->children[i]->insertNonFull(k);

            // Update root
            root = s;
        } else {
            // Root is not full, insert directly
            root->insertNonFull(k);
        }
    }
}

// Insert a key into a node that is not full
void BTreeNode::insertNonFull(int k) {
    int i = n - 1;

    if (leaf) {
        // Shift keys to make space for new key
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }
        // Place new key in correct position
        keys[i + 1] = k;
        n++;
    } else {
        // Find child to insert into
        while (i >= 0 && keys[i] > k) i--;
        i++;

        // If child is full, split it first
        if (children[i]->n == 2 * T - 1) {
            splitChild(i, children[i]);
            if (keys[i] < k) i++;
        }

        // Insert into the correct child
        children[i]->insertNonFull(k);
    }
}

// Split a full child y of this node at index i
void BTreeNode::splitChild(int i, BTreeNode* y) {
    // Create new node z to store T-1 keys from y
    BTreeNode* z = new BTreeNode(y->leaf);
    z->n = T - 1;

    // Copy keys from y to z
    for (int j = 0; j < T - 1; j++)
        z->keys[j] = y->keys[j + T];

    // If not leaf, copy children too
    if (!y->leaf) {
        for (int j = 0; j < T; j++)
            z->children[j] = y->children[j + T];
    }

    y->n = T - 1; // Reduce number of keys in y

    // Shift this node’s children to make space
    for (int j = n; j >= i + 1; j--)
        children[j + 1] = children[j];

    children[i + 1] = z; // Link new child

    // Shift keys to make space
    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    // Move middle key from y to this node
    keys[i] = y->keys[T - 1];
    n++;
}

// QUESTION 6

// Remove a key from the B-tree
void BTree::remove(int k) {
    if (!root) return;

    root->remove(k); // Call recursive remove on root

    // If root becomes empty
    if (root->n == 0) {
        BTreeNode* tmp = root;
        if (root->leaf)
            root = nullptr;
        else
            root = root->children[0];
        delete tmp;
    }
}

// Find the index of first key ≥ k
int BTreeNode::findKey(int k) {
    int idx = 0;
    while (idx < n && keys[idx] < k) ++idx;
    return idx;
}

// Remove a key from subtree rooted at this node
void BTreeNode::remove(int k) {
    int idx = findKey(k);

    if (idx < n && keys[idx] == k) {
        // Case 1: key is in this node
        if (leaf)
            removeFromLeaf(idx);
        else
            removeFromNonLeaf(idx);
    } else {
        // Case 2: key is not in this node
        if (leaf) return; // Not found in leaf

        // Check if child has minimum keys
        bool flag = (idx == n); // Check if it's the last child
        if (children[idx]->n < T)
            fill(idx); // Fill child if needed

        // After filling, recurse
        if (flag && idx > n)
            children[idx - 1]->remove(k);
        else
            children[idx]->remove(k);
    }
}

// Remove key from leaf node
void BTreeNode::removeFromLeaf(int idx) {
    // Shift keys to remove the key
    for (int i = idx + 1; i < n; ++i)
        keys[i - 1] = keys[i];
    n--;
}

// Remove key from non-leaf node
void BTreeNode::removeFromNonLeaf(int idx) {
    int k = keys[idx];  // Store the key to be deleted

    // CASE 1: If the child before the key (left child) has at least T keys
    if (children[idx]->n >= T) {
        int pred = getPredecessor(idx);   // Find the predecessor of key[idx]
        keys[idx] = pred;                 // Replace the key with predecessor
        children[idx]->remove(pred);      // Recursively delete predecessor in left subtree

    // CASE 2: Else if the child after the key (right child) has at least T keys
    } else if (children[idx + 1]->n >= T) {
        int succ = getSuccessor(idx);     // Find the successor of key[idx]
        keys[idx] = succ;                 // Replace the key with successor
        children[idx + 1]->remove(succ);  // Recursively delete successor in right subtree

    // CASE 3: Both children have only T-1 keys
    } else {
        merge(idx);                       // Merge left and right children with key[idx]
        children[idx]->remove(k);         // Recursively delete key from merged child
    }
}

// Get predecessor of key at idx
int BTreeNode::getPredecessor(int idx) {
    BTreeNode* cur = children[idx];           // Go to left child
    while (!cur->leaf)                        // Keep moving to the rightmost child
        cur = cur->children[cur->n];          // Last key in subtree
    return cur->keys[cur->n - 1];             // Return rightmost key (predecessor)
}

// Get successor of key at idx
int BTreeNode::getSuccessor(int idx) {
    BTreeNode* cur = children[idx + 1];       // Go to right child
    while (!cur->leaf)                        // Keep moving to the leftmost child
        cur = cur->children[0];               // First key in subtree
    return cur->keys[0];                      // Return leftmost key (successor)
}

// Ensure child has at least T keys
void BTreeNode::fill(int idx) {
    // If previous sibling exists and has ≥ T keys, borrow from it
    if (idx != 0 && children[idx - 1]->n >= T)
        borrowFromPrev(idx);

    // Else if next sibling exists and has ≥ T keys, borrow from it
    else if (idx != n && children[idx + 1]->n >= T)
        borrowFromNext(idx);

    // Else, merge with a sibling
    else {
        // Prefer merging with next sibling if possible
        if (idx != n)
            merge(idx);
        else
            merge(idx - 1); // Otherwise, merge with previous sibling
    }
}

// Borrow a key from previous sibling
void BTreeNode::borrowFromPrev(int idx) {
    BTreeNode* child = children[idx];              // Target child (underflow)
    BTreeNode* sibling = children[idx - 1];        // Left sibling

    // Shift child’s keys forward to make space for borrowed key
    for (int i = child->n - 1; i >= 0; --i)
        child->keys[i + 1] = child->keys[i];

    // If child is not leaf, shift its children as well
    if (!child->leaf) {
        for (int i = child->n; i >= 0; --i)
            child->children[i + 1] = child->children[i];
    }

    // Move key from parent to child
    child->keys[0] = keys[idx - 1];

    // Move sibling’s last child to child if not leaf
    if (!child->leaf)
        child->children[0] = sibling->children[sibling->n];

    // Move sibling’s last key up to parent
    keys[idx - 1] = sibling->keys[sibling->n - 1];

    child->n++;         // Child now has one more key
    sibling->n--;       // Sibling has one fewer key
}

// Borrow a key from next sibling
void BTreeNode::borrowFromNext(int idx) {
    BTreeNode* child = children[idx];              // Target child (underflow)
    BTreeNode* sibling = children[idx + 1];        // Right sibling

    // Move parent’s key down to child
    child->keys[child->n] = keys[idx];

    // If child is not leaf, move sibling’s first child to child
    if (!child->leaf)
        child->children[child->n + 1] = sibling->children[0];

    // Move sibling’s first key up to parent
    keys[idx] = sibling->keys[0];

    // Shift sibling’s keys and children left to fill gap
    for (int i = 1; i < sibling->n; ++i)
        sibling->keys[i - 1] = sibling->keys[i];

    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->n; ++i)
            sibling->children[i - 1] = sibling->children[i];
    }

    child->n++;        // Child gains a key
    sibling->n--;      // Sibling loses a key
}

// Merge child at idx with its sibling
void BTreeNode::merge(int idx) {
    BTreeNode* child = children[idx];          // Left child
    BTreeNode* sibling = children[idx + 1];    // Right sibling

    // Pull key from parent down into child
    child->keys[T - 1] = keys[idx];

    // Copy sibling’s keys to child
    for (int i = 0; i < sibling->n; ++i)
        child->keys[i + T] = sibling->keys[i];

    // Copy sibling’s children to child (if not leaf)
    if (!child->leaf) {
        for (int i = 0; i <= sibling->n; ++i)
            child->children[i + T] = sibling->children[i];
    }

    // Shift parent keys and children left to fill removed key/child
    for (int i = idx + 1; i < n; ++i)
        keys[i - 1] = keys[i];

    for (int i = idx + 2; i <= n; ++i)
        children[i - 1] = children[i];

    child->n += sibling->n + 1;  // Update key count in merged node
    n--;                         // Parent has one fewer key

    delete sibling;              // Free memory
}

int main() {
    BTree tree;

    // Insert keys
    int values[] = {10, 20, 5, 6, 12, 30, 7, 17};
    cout << "Inserting: ";
    for (int val : values) {
        cout << val << " ";
        tree.insert(val);
    }

    cout << "\n\nTraversal after insertions:\n";
    tree.traverse();

    // Delete examples
    tree.remove(6);  cout << "\n\nAfter removing 6:\n"; tree.traverse();
    tree.remove(13); cout << "\n\nAfter removing 13 (not found):\n"; tree.traverse();
    tree.remove(7);  cout << "\n\nAfter removing 7:\n"; tree.traverse();
    tree.remove(4);  cout << "\n\nAfter removing 4 (not found):\n"; tree.traverse();
    tree.remove(12); cout << "\n\nAfter removing 12:\n"; tree.traverse();
    cout << endl;

    return 0;
}
