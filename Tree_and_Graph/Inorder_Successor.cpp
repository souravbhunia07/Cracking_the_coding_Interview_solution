#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr), parent(nullptr) {}
};

TreeNode* findInOrderSuccessor(TreeNode* node) {
    if (node == nullptr) return nullptr;

    // Case 1: Node has a right subtree
    if (node->right) {
        node = node->right;
        while (node->left)
            node = node->left;
        return node;
    }

    // Case 2: Node does not have a right subtree
    while (node->parent && node == node->parent->right)
        node = node->parent;

    return node->parent;
}

// Helper function to insert a node into the binary search tree
TreeNode* insert(TreeNode* root, int value, TreeNode* parent = nullptr) {
    if (root == nullptr) {
        root = new TreeNode(value);
        root->parent = parent;
    } else if (value < root->val) {
        root->left = insert(root->left, value, root);
    } else {
        root->right = insert(root->right, value, root);
    }
    return root;
}

void inorder(TreeNode *root) {
    if (root == nullptr) return; 
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // Create a binary search tree
    TreeNode* root = nullptr;
    root = insert(root, 5);
    // insert(root, 3);
    // insert(root, 10);
    // insert(root, 1);
    // insert(root, 6);
    // insert(root, 14);
    // insert(root, 4);
    // insert(root, 7);
    // insert(root, 13);

    insert(root, 1);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 9);
    insert(root, 3);
    insert(root, 8);
    insert(root, 10);

    inorder(root);

    cout << endl;

    // Find the in-order successor of a given node
    TreeNode* givenNode = root->left->right;
    TreeNode* successor = findInOrderSuccessor(givenNode);

    if (successor)
        std::cout << "The in-order successor of " << givenNode->val << " is " << successor->val << std::endl;
    else
        std::cout << givenNode->val << " does not have an in-order successor." << std::endl;

    return 0;
}
