#include <iostream>
using namespace std;
// Node structure for Binary Tree
struct Node {
    string data;
    Node* left;
    Node* right;
};
// Function to create a new node
Node* createNode(string data) {
    Node* newNode = new Node{data, NULL, NULL};
    return newNode;
}
// In-order Traversal (Left, Root, Right)
void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}
void preorderTraversal(Node* root) {
    if (root) {
    	cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void postorderTraversal(Node* root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}
int main() {
    // Creating binary tree manually
    Node* root = createNode("AND");
    root->left = createNode("OR");
    root->right = createNode("OR");
    root->left->left = createNode("A");
    root->left->right = createNode("B");
    root->right->left = createNode("C");
    root->right->right = createNode("D");

    cout << "In-order Traversal of Binary Tree:\n";
    inorderTraversal(root);
    cout << endl;
	cout << "Pre-order Traversal of Binary Tree:\n";
    preorderTraversal(root);
    cout << endl;
    cout << "Post-order Traversal of Binary Tree:\n";
    postorderTraversal(root);
    cout << endl;
    return 0;
}

