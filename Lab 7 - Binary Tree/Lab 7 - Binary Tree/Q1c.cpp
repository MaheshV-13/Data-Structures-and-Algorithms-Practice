#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    vector<TreeNode*> children;
};

TreeNode* createNode(int value) {
    return new TreeNode{value};
}

void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->data << " ";
    for (size_t i = 0; i < root->children.size(); i++)
        preorder(root->children[i]);
}

void postorder(TreeNode* root) {
    if (!root) return;
    for (size_t i = 0; i < root->children.size(); i++)
        postorder(root->children[i]);
    cout << root->data << " ";
}

void inorder(TreeNode* root) {
    if (!root) return;
    if (root->children.size() > 0)
        inorder(root->children[0]);
    cout << root->data << " "; 
    for (size_t i = 1; i < root->children.size(); i++)
        inorder(root->children[i]);
}

void printTree(TreeNode* root, int level = 0) {
    if (!root) return;
    for (int i = 0; i < level; i++) cout << "  ";
    cout << root->data << endl;
    for (size_t i = 0; i < root->children.size(); i++)
        printTree(root->children[i], level + 1);
}

int main() {
    TreeNode* root = createNode(1);
    TreeNode* child1 = createNode(2);
    TreeNode* child2 = createNode(3);
    TreeNode* child3 = createNode(4);

    root->children.push_back(child1);
    root->children.push_back(child2);
    child1->children.push_back(child3);

    cout << "Tree Structure:\n";
    printTree(root);

    cout << "\nPre-order Traversal: ";
    preorder(root);

    cout << "\nPost-order Traversal: ";
    postorder(root);

    cout << "\nIn-order Traversal: ";
    inorder(root);

    cout << endl;
    return 0;
}

