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

void partition(Node*& head, int x) {
    Node* left_head = nullptr;
    Node* left_tail = nullptr;
    Node* right_head = nullptr;
    Node* right_tail = nullptr;

    Node* current = head;

    while (current != nullptr) {
        if (current->data < x) {
            if (left_head == nullptr) {
                left_head = current;
                left_tail = current;
            } else {
                left_tail->Next = current;
                left_tail = current;
            }
        } else {
            if (right_head == nullptr) {
                right_head = current;
                right_tail = current;
            } else {
                right_tail->Next = current;
                right_tail = current;
            }
        }

        current = current->Next;
    }

    // Set the Next pointer of the last node in the right list to nullptr.
    if (right_tail != nullptr) {
        right_tail->Next = nullptr;
    }

    // Update the head of the main list to the head of the left list (if not empty),
    // otherwise, update it to the head of the right list.
    if (left_head != nullptr) {
        head = left_head;
        left_tail->Next = right_head;
    } else {
        head = right_head;
    }
}


int main()
{
    Node *first = nullptr;
    int arr[] = {3, 5, 8, 5, 10, 2, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    create(arr, size, first);
    Rdisplay(first);
    cout << endl;
    Node *n = first->Next->Next->Next->Next;
    Node *temp = first;
    for(int i = 0; i < 3; i++)
    {
        temp = temp->Next;
    }
    partition(first, 5);
    Rdisplay(first);
    return 0;
}
