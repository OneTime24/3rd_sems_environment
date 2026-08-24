

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;

};

void Display(Node *head)
{
    if(head == nullptr)
    {
        cout << "List is empty\n";
        return;
    }

    Node *p = head;

    do
    {
        cout << p->data << " ";
        p = p->next;
    }
    while(p != head);

    cout << endl;
}
void InsertFirst(Node *&head, int x)
{
    Node *t = new Node;
    t->data = x;

    // Empty list
    if(head == nullptr)
    {
        t->next = t;
        head = t;
        return;
    }

    // Find last node
    Node *p = head;

    while(p->next != head)
    {
        p = p->next;
    }

    t->next = head;
    p->next = t;
    head = t;
}


void InsertLast(Node *&head, int x)
{
    Node *t = new Node;
    t->data = x;

    // Empty list
    if(head == nullptr)
    {
        t->next = t;
        head = t;
        return;
    }

    Node *p = head;

    while(p->next != head)
    {
        p = p->next;
    }

    p->next = t;
    t->next = head;
}

void DeleteFirst(Node *&head)
{
    if(head == nullptr)
        return;

    // Only one node
    if(head->next == head)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node *last = head;

    while(last->next != head)
    {
        last = last->next;
    }

    Node *temp = head;

    head = head->next;
    last->next = head;

    delete temp;
}
int main()
{
    Node *head = nullptr;

    InsertFirst(head, 30);
    InsertFirst(head, 20);
    InsertFirst(head, 10);

    cout << "After InsertFirst:\n";
    Display(head);

    InsertLast(head, 40);
    InsertLast(head, 50);

    cout << "After InsertLast:\n";
    Display(head);

    DeleteFirst(head);

    cout << "After DeleteFirst:\n";
    Display(head);

    return 0;
}