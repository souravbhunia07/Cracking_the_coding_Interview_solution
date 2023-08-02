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

void returnKthToLast(Node* head, int n)
{
    // If the list is empty or n is negative, there's nothing to return.
    if (head == NULL || n <= 0)
        return;

    Node* start = new Node; // Create a new dummy node.
    start->Next = head;
    Node* fast = start, * slow = start;

    // Move fast n nodes ahead.
    for (int i = 0; i <= n; i++)
    {
        if (fast == NULL) // If n is greater than the list size, return.
            return;
        fast = fast->Next;
    }

    // Move both pointers until fast reaches the end of the list.
    while (fast != NULL)
    {
        fast = fast->Next;
        slow = slow->Next;
    }

    // Now, slow is pointing to the node before the kth node from the last.
    // We can remove the kth node from the last as follows:
    Node* temp = slow->Next;
    slow->Next = slow->Next->Next;
    delete temp; // Deallocate the memory of the removed node.
}

int main()
{
    Node *first = nullptr;
    int arr[] = {1, 5, 2, 5, 8, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    create(arr, size, first);
    Rdisplay(first);
    cout << endl;
    returnKthToLast(first, 1);
    Rdisplay(first);
    return 0;
}
