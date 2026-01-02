#include <iostream>
using namespace std;

// Node structure for Binary Tree
struct Node {
    int data; // value for the node
    Node* left; // pointer to left child
    Node* right; // pointer to right child
    // since its a binary tree, a parent node can only have a maximum of 2 child node (left, right)
};

// Function to create a new node
Node* createNode(int data) { // takes a value as the parameter
    Node* newNode = new Node{data, NULL, NULL}; // creates a node with the value and no left and right pointer (no child yet)
    return newNode; // returns pointer to newNode
}

// In-order Traversal (Left, Root, Right)
void inorderTraversal(Node* root) {
    if (root) { // checks if node exists 
        inorderTraversal(root->left); // recursive function to traverse the left subtree
        cout << root->data << " "; // prints root value
        inorderTraversal(root->right); // recursive function to traverse right subtree
    }
}

int main() {
    // Creating binary tree manually
    Node* root = createNode(10); // root node = 10
    root->left = createNode(5); // left child of root node(10)= 5
    root->right = createNode(15); // left child of root node(10) = 15
    root->left->left = createNode(3);// left child of parent node(5) = 3
    root->left->right = createNode(7);// right child of parent node(5) = 7
    root->right->left = createNode(12);// left child of parent node(15) = 12
    root->right->right = createNode(17);// right child of parent node(15) = 17

    cout << "In-order Traversal of Binary Tree:\n";
    inorderTraversal(root);
    cout << endl;

    return 0;
}

