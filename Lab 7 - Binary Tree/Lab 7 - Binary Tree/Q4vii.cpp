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
    Node* root = createNode("+");
    root->left = createNode("*");
    root->right = createNode("-");
    root->left->left = createNode("-");
    root->left->right = createNode("+");
    root->right->left = createNode("10");
    root->right->right = createNode("*");
    root->left->left->left = createNode("*");
    root->left->left->right = createNode("7");
    root->left->right->left = createNode("2");
    root->left->right->right = createNode("7");
    root->right->right->left = createNode("+");
    root->right->right->right = createNode("-1");
    root->left->left->left->left = createNode("5");
    root->left->left->left->right = createNode("+");
    root->right->right->left->left = createNode("6");
    root->right->right->left->right = createNode("8");
    root->left->left->left->right->left = createNode("2");
    root->left->left->left->right->right = createNode("2");

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

