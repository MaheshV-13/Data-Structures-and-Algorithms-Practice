#include <iostream>
#include <vector>
using namespace std;

// Node structure for general tree
struct TreeNode {
    int data; // value in the node
    vector<TreeNode*> children;  // Can have multiple children
};

// Function to print tree (DFS Traversal)
void printTree(TreeNode* root, int level = 0) { // pointer points to the root node, at L0
    if (!root) return; // if the node is null, then do nothing 
    
    // Print with indentation based on level
    for (int i = 0; i < level; i++) cout << "  "; // for each level, prints "  "
    cout << root->data << endl;  // prints current node value + newline
    
    for (size_t i = 0; i < root->children.size(); i++) 
    printTree(root->children[i], level + 1); // a recursive loop to print all nodes until it reaches leaf node
}

int main() {
    // Creating tree manually
    TreeNode* root = new TreeNode{1};
    TreeNode* child1 = new TreeNode{2};
    TreeNode* child2 = new TreeNode{3};
    TreeNode* child3 = new TreeNode{4}; // creating 4 nodes with values 1,2,3,4

    root->children.push_back(child1);
    root->children.push_back(child2);
    child1->children.push_back(child3); // connecting child 1,2 to root node and child 3 to child 1

    cout << "Tree Structure:\n";
    printTree(root); // start with printing root node

    return 0;
}

