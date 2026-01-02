#include <iostream>
#include <vector>
using namespace std;

// Node structure for general tree
struct TreeNode {
    int data;
    vector<TreeNode*> children;  // Can have multiple children
};

// Function to create a new tree node
TreeNode* createNode(int value) {
    return new TreeNode{value};
}

// DFS traversal to print tree
void printTree(TreeNode* root, int level = 0) {
    if (!root) return;

    // Indentation based on tree level
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
    TreeNode* child4 = createNode(5);
    TreeNode* child5 = createNode(6);
    TreeNode* child6 = createNode(7);
    TreeNode* child7 = createNode(8);

    root->children.push_back(child1);
    root->children.push_back(child2);

    child1->children.push_back(child3);
    child1->children.push_back(child4);

    child4->children.push_back(child5);
    child4->children.push_back(child6);
    child4->children.push_back(child7);

    cout << "General Tree Structure:\n";
    printTree(root);

    return 0;
}

