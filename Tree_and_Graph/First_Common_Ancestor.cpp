#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base Case
        if (root == NULL || root == q || root == p) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (right == NULL) {
            return left;
        } else if (left == NULL) {
            return right;
        } else {
            return root;
        }
    }
};

int main() {
    // Create a binary tree (same as the previous example)
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);
    root->left->left->right = new TreeNode(7);

    Solution solution;
    TreeNode* p = root->left->left->left; // Node 6
    TreeNode* q = root->left->right;      // Node 5

    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);
    std::cout << "Lowest Common Ancestor: " << lca->val << std::endl;

    // Clean up memory (not shown in this example)

    return 0;
}
