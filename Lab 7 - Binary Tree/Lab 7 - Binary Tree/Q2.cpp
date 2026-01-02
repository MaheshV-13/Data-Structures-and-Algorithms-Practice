#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int value) {
    if (root == NULL) return NULL;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

bool update(Node* root, int oldVal, int newVal) {
    Node* curr = root;
    while (curr != NULL) {
        if (oldVal < curr->data)
            curr = curr->left;
        else if (oldVal > curr->data)
            curr = curr->right;
        else
            break;
    }

    if (curr == NULL) return false;

    root = deleteNode(root, oldVal);
    root = insert(root, newVal);
    return true;
}

int main() {
    Node* root = NULL;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        root = insert(root, values[i]);

    cout << "In-order Traversal of Tree:\n";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 30);
    cout << "After deleting 30:\n";
    inorder(root);
    cout << endl;

    update(root, 70, 75);
    cout << "After updating 70 to 75:\n";
    inorder(root);
    cout << endl;

    return 0;
}

