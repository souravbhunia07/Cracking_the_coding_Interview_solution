// O(1)

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *Next;
};

void create(int arr[], int n, Node *&first)
{
    Node *t, *last;
    first = new Node;
    first->data = arr[0];
    first->Next = nullptr;
    last = first;
    for(int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = arr[i];
        t->Next = nullptr;
        last->Next = t;
        last = t;
    }
}

void Rdisplay(Node *p)
{
    if(p != NULL)
    {
       cout << p->data << " ";
       Rdisplay(p->Next); 
    }
}

void deleteMiddleNode(Node* middleNode) {
    // Check if the given node or its next node is null
    if (middleNode == nullptr || middleNode->Next == nullptr) {
        return; // Can't delete the node if it's the last node or nullptr.
    }

    // Copy the data of the next node to the current node.
    Node* nextNode = middleNode->Next;
    middleNode->data = nextNode->data;

    // Update the "Next" pointer of the current node.
    middleNode->Next = nextNode->Next;

    // Delete the next node.
    delete nextNode;
}

int main()
{
    Node *first = nullptr;
    int arr[] = {1, 5, 2, 5, 8, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    create(arr, size, first);
    Rdisplay(first);
    cout << endl;
    Node *n = first->Next->Next->Next->Next;
    deleteMiddleNode(n);
    Rdisplay(first);
    return 0;
}
