#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Definition for a singly linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<ListNode*> createLinkedLists(TreeNode* root) {
    vector<ListNode*> result;

    if (!root) {
        return result;
    }

    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        int levelSize = nodeQueue.size();
        ListNode* levelHead = nullptr;
        ListNode* current = nullptr;

        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();

            if (!levelHead) {
                levelHead = new ListNode(node->val);
                current = levelHead;
            } else {
                current->next = new ListNode(node->val);
                current = current->next;
            }

            if (node->left) {
                nodeQueue.push(node->left);
            }

            if (node->right) {
                nodeQueue.push(node->right);
            }
        }

        result.push_back(levelHead);
    }

    return result;
}

// Helper function to delete linked lists to prevent memory leaks
void deleteLinkedLists(vector<ListNode*>& lists) {
    for (ListNode* head : lists) {
        ListNode* current = head;
        while (current) {
            ListNode* temp = current;
            current = current->next;
            delete temp;
        }
    }
}

// Helper function to print linked lists
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// Helper function to delete binary tree nodes to prevent memory leaks
void deleteTree(TreeNode* root) {
    if (!root) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<ListNode*> lists = createLinkedLists(root);

    // Print the linked lists for each depth
    for (int i = 0; i < lists.size(); i++) {
        cout << "Linked List at depth " << i << ": ";
        printLinkedList(lists[i]);
    }

    // Clean up memory
    deleteLinkedLists(lists);
    deleteTree(root);

    return 0;
}

