#include <iostream>
#include <vector>

// Tree node definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val) {
            return root;
        }

        if (val < root->val) {
            return searchBST(root->left, val);
        } else {
            return searchBST(root->right, val);
        }
    }

    void getLeafNodes(TreeNode* root, std::vector<int>& leafNodes) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            leafNodes.push_back(root->val);
            return;
        }

        getLeafNodes(root->left, leafNodes);
        getLeafNodes(root->right, leafNodes);
    }
};

std::vector<int> getSubtreeAndLeafNodes(TreeNode* root, int target) {
    Solution solution;
    TreeNode* subtreeRoot = solution.searchBST(root, target);
    std::vector<int> leafNodes;
    if (subtreeRoot != nullptr) {
        solution.getLeafNodes(subtreeRoot, leafNodes);
    }
    return leafNodes;
}

int main() {
    // Create a binary search tree
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    int target = 2;

    // Get the subtree rooted at the target value and its leaf nodes
    std::vector<int> leafNodes = getSubtreeAndLeafNodes(root, target);

    // Check if the subtree is found
    if (!leafNodes.empty()) {
        std::cout << "Subtree rooted at value " << target << " found in the BST." << std::endl;
        std::cout << "Leaf nodes in the subtree: ";
        for (int leaf : leafNodes) {
            std::cout << leaf << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Subtree rooted at value " << target << " not found in the BST." << std::endl;
    }

    return 0;
}
