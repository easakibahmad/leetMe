#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        swap(root->left, root->right);

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

// Helper function to create a sample binary tree
TreeNode* createBinaryTree() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    return root;
}

// Helper function to print the tree in preorder traversal
void printPreorder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
   cout << node->val << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    Solution solution;
    TreeNode* root = createBinaryTree();

   cout << "Original Tree (preorder): ";
    printPreorder(root);
    cout << endl;

    TreeNode* invertedTree = solution.invertTree(root);

    cout << "Inverted Tree (preorder): ";
    printPreorder(invertedTree);
    cout << endl;

    // Clean up memory (optional)
    // ... (delete the tree nodes)

    return 0;
}
