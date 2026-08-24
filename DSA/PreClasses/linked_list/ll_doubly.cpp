#include <iostream>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;
};

void DisplayForward(Node *head)
{
    while(head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void DisplayBackward(Node *head)
{
    if(head == nullptr) return;

    while(head->next != nullptr)
        head = head->next;

    while(head != nullptr)
    {
        cout << head->data << " ";
        head = head->prev;
    }
    cout << endl;
}

void InsertFirst(Node *&head,int x)
{
    Node *t = new Node;
    t->data = x;
    t->prev = nullptr;
    t->next = head;

    if(head != nullptr)
        head->prev = t;

    head = t;
}

void InsertLast(Node *&head,int x)
{
    Node *t = new Node;
    t->data = x;
    t->next = nullptr;

    if(head == nullptr)
    {
        t->prev = nullptr;
        head = t;
        return;
    }

    Node *p = head;

    while(p->next != nullptr)
        p = p->next;

    p->next = t;
    t->prev = p;
}

void DeleteFirst(Node *&head)
{
    if(head == nullptr)
        return;

    Node *temp = head;

    head = head->next;

    if(head != nullptr)
        head->prev = nullptr;

    delete temp;
}

void DeleteLast(Node *&head)
{
    if(head == nullptr)
        return;

    if(head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node *p = head;

    while(p->next != nullptr)
        p = p->next;

    p->prev->next = nullptr;

    delete p;
}

int main()
{
    Node *head = nullptr;

    InsertFirst(head,30);
    InsertFirst(head,20);
    InsertFirst(head,10);

    InsertLast(head,40);
    InsertLast(head,50);

    cout<<"Forward: ";
    DisplayForward(head);

    cout<<"Backward: ";
    DisplayBackward(head);

    DeleteFirst(head);

    cout<<"After DeleteFirst: ";
    DisplayForward(head);

    DeleteLast(head);

    cout<<"After DeleteLast: ";
    DisplayForward(head);

    return 0;
}