#include <iostream>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = nullptr;

// Inserting in BST.

void insert(int key)
{
    Node *t = root;
    Node *r = nullptr;
    Node *p;
    if (root == nullptr)
    {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = nullptr;
        root = p;
        return;
    }
    while (t != nullptr)
    {
        r = t;
        if (key > t->data)
        {
            t = t->rchild;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            return;
        }
    }
    p = new Node;
    p->data = key;
    p->lchild = p->rchild = nullptr;
    if (key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

struct Node * Rinsert(struct Node *p, int key)
{
    Node *t = NULL;
    if (p == NULL)
    {
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
    {
        p->lchild = Rinsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Rinsert(p->rchild, key);
    }
    return p;
}

void inorder(struct Node *p)
{
    if(!p)
    {
        return;
    }
    inorder(p->lchild);
    cout << p->data << " ";
    inorder(p->rchild);
}

int main()
{
    int n;
    cout << "Enter the size of the array:- ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        insert(arr[i]);
    }

    // for Recursive insertion.

    // root = Rinsert(root, 10);
    // Rinsert(root, 8);
    // Rinsert(root, 20);
    // Rinsert(root, 4);
    // Rinsert(root, 30);

    inorder(root);
    cout << endl;
    
    return 0;
}
