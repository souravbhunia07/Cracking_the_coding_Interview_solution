#include <iostream>
#include <cmath>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

bool ValidateBst(TreeNode *root, TreeNode *min, TreeNode *max)
{
    if (root == nullptr) {
        return true;
    }

    if ((min != nullptr && root->val <= min->val) || (max != nullptr && root->val >= max->val)) {
        return false;
    }

    return ValidateBst(root->left, min, root) && ValidateBst(root->right, root, max);
}


// Helper function to create a binary tree node
TreeNode* createNode(int val) {
    return new TreeNode(val);
}

int main() {
    // Example usage:
    // TreeNode* root = createNode(1);
    // root->left = createNode(2);
    // root->right = createNode(3);
    // root->left->left = createNode(4);
    // root->left->right = createNode(5);
    // root->right->right = createNode(6);

    TreeNode* root = createNode(2);
    root->left = createNode(1);
    root->right = createNode(3);

    if (ValidateBst(root, NULL, NULL)) {
        std::cout << "It is a BST." << std::endl;
    } else {
        std::cout << "It is not a BST." << std::endl;
    }

    return 0;
}
