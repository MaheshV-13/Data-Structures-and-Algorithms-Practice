#include <iostream>
#include <vector>
using namespace std;

// Node structure for general tree
struct TreeNode {
    string data;
    vector<TreeNode*> children;  // Can have multiple children
};

// Function to create a new tree node
TreeNode* createNode(string value) {
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
    TreeNode* root = createNode("A");
    TreeNode* child1 = createNode("B");
    TreeNode* child2 = createNode("C");
    TreeNode* child3 = createNode("D");
    TreeNode* child4 = createNode("E");
    TreeNode* child5 = createNode("F");
    TreeNode* child6 = createNode("G");
    TreeNode* child7 = createNode("H");
    TreeNode* child8 = createNode("I");
    TreeNode* child9 = createNode("J");
    TreeNode* child10 = createNode("K");
    TreeNode* child11 = createNode("L");
    TreeNode* child12 = createNode("M");
    TreeNode* child13 = createNode("N");
    TreeNode* child14 = createNode("O");

    root->children.push_back(child1);
    root->children.push_back(child2);
    root->children.push_back(child3);

    child1->children.push_back(child4);
    child1->children.push_back(child5);

    child3->children.push_back(child6);
    child3->children.push_back(child7);
    child3->children.push_back(child8);
    
    child5->children.push_back(child9);
    child5->children.push_back(child10);

	child7->children.push_back(child11);
	
	child9->children.push_back(child12);
	
	child11->children.push_back(child13);
	child11->children.push_back(child14);

    cout << "General Tree Structure:\n";
    printTree(root);

    return 0;
}

