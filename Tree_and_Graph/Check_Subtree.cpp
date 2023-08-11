#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *s, TreeNode *t) {
        if (!s || !t) {
            return s == NULL && t == NULL;
        } else if (s->val == t->val) {
            return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
        } else {
            return false;
        }
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        } else if (isSameTree(root, subRoot)) {
            return true;
        } else {
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
    }
};

int main() {
    Solution solution;

    // Create the root tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    // Create the subRoot tree
    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    // Check if subRoot is a subtree of root
    bool result = solution.isSubtree(root, subRoot);

    // Output the result
    std::cout << "Is subRoot a subtree of root? " << (result ? "true" : "false") << std::endl;

    return 0;
}
