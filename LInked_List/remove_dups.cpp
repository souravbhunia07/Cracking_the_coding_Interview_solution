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

// O(N^2)

void removeDuplicates(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* runner = current;
        while (runner->Next != nullptr) {
            if (runner->Next->data == current->data) {
                // Duplicate found, remove the node
                Node* temp = runner->Next;
                runner->Next = runner->Next->Next;
                delete temp;
            } else {
                // Move to the next node
                runner = runner->Next;
            }
        }
        current = current->Next;
    }
}

// TC - O(N)
// SC - O(N)

void removeDups(Node * head)
{
    if(head == nullptr)
    {
        return;
    }

    Node *prev = nullptr;
    Node *curr = head;
    unordered_set<int> seen;

    while(curr != NULL)
    {
        if(seen.find(curr->data) != seen.end())
        {
            // Duplicate found, remove the node
            prev->Next = curr->Next;
            delete curr;
            curr = prev->Next;
        }
        else
        {
            // New element, add it to the hash set
            seen.insert(curr->data);
            prev = curr;
            curr = curr->Next;
        }
    }
}

int main()
{
    Node *first = nullptr;
    int arr[] = {1, 5, 2, 5, 8, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    create(arr, size, first);
    Rdisplay(first);
    cout << endl;
    removeDuplicates(first);
    Rdisplay(first);
    return 0;
}
