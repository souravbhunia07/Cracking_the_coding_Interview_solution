#include <iostream>
#include <cmath>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

// Function to calculate the height of the binary tree
int height(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + std::max(height(root->left), height(root->right));
}

// Function to check if the binary tree is balanced
bool isBalanced(TreeNode* root) {
    if (root == nullptr) return true;

    int left_height = height(root->left);
    int right_height = height(root->right);

    // Check if the difference in heights is not more than 1
    if (std::abs(left_height - right_height) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
        return true;
    }

    return false;
}

// Helper function to create a binary tree node
TreeNode* createNode(int val) {
    return new TreeNode(val);
}

int main() {
    // Example usage:
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    if (isBalanced(root)) {
        std::cout << "The binary tree is balanced." << std::endl;
    } else {
        std::cout << "The binary tree is not balanced." << std::endl;
    }

    return 0;
}
