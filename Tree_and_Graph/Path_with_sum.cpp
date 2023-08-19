#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root)
            return 0;
        
        int pathsFromRoot = countPaths(root, sum); // Paths starting from root
        int pathsLeft = pathSum(root->left, sum);   // Paths in left subtree
        int pathsRight = pathSum(root->right, sum); // Paths in right subtree
        
        return pathsFromRoot + pathsLeft + pathsRight;
    }
    
private:
    int countPaths(TreeNode* node, int targetSum) {
        if (!node)
            return 0;
        
        int count = 0;
        if (node->val == targetSum)
            count++;
        
        count += countPaths(node->left, targetSum - node->val);
        count += countPaths(node->right, targetSum - node->val);
        
        return count;
    }
};

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    Solution solution;
    int targetSum = 8;
    int count = solution.pathSum(root, targetSum);
    std::cout << "Number of paths that sum to " << targetSum << ": " << count << std::endl;

    // Clean up memory (not shown in this simplified example)
    
    return 0;
}
