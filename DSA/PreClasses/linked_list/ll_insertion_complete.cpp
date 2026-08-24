#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = nullptr;
Node *last = nullptr;

// Insert at any position
void Insert(int pos, int x)
{
    Node *t = new Node;
    t->data = x;
    t->next = nullptr;

    // Case 1: Empty list
    if (head == nullptr)
    {
        head = last = t;
        return;
    }

    // Case 2: Insert at beginning
    if (pos == 0)
    {
        t->next = head;
        head = t;
        return;
    }

    // Case 3: Insert at any other position
    Node *p = head;

    for (int i = 0; i < pos - 1 && p != nullptr; i++)
    {
        p = p->next;
    }

    if (p != nullptr)
    {
        t->next = p->next;
        p->next = t;

        // If inserted at the end, update last
        if (t->next == nullptr)
            last = t;
    }
}

// Fast insertion at end using last pointer
void InsertLast(int x)
{
    Node *t = new Node;
    t->data = x;
    t->next = nullptr;

    // Empty list
    if (head == nullptr)
    {
        head = last = t;
        return;
    }

    last->next = t;
    last = t;
}

void Display(Node *p)
{
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    // Using Insert()
    Insert(0, 10);
    Insert(1, 20);
    Insert(2, 30);
    Insert(1, 15);

    Display(head);

    // Using InsertLast()
    InsertLast(40);
    InsertLast(50);

    Display(head);
}