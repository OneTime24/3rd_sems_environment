#include <iostream>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;
};

void Display(Node *head)
{
    if(head == nullptr)
    {
        cout<<"List is empty\n";
        return;
    }

    Node *p = head;

    do
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    while(p != head);

    cout<<endl;
}

void InsertFirst(Node *&head,int x)
{
    Node *t = new Node;
    t->data = x;

    if(head == nullptr)
    {
        t->next = t;
        t->prev = t;
        head = t;
        return;
    }

    Node *last = head->prev;

    t->next = head;
    t->prev = last;

    last->next = t;
    head->prev = t;

    head = t;
}

void InsertLast(Node *&head,int x)
{
    Node *t = new Node;
    t->data = x;

    if(head == nullptr)
    {
        t->next = t;
        t->prev = t;
        head = t;
        return;
    }

    Node *last = head->prev;

    t->next = head;
    t->prev = last;

    last->next = t;
    head->prev = t;
}

void DeleteFirst(Node *&head)
{
    if(head == nullptr)
        return;

    if(head->next == head)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node *last = head->prev;
    Node *temp = head;

    head = head->next;

    head->prev = last;
    last->next = head;

    delete temp;
}

void DeleteLast(Node *&head)
{
    if(head == nullptr)
        return;

    if(head->next == head)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node *last = head->prev;
    Node *newLast = last->prev;

    newLast->next = head;
    head->prev = newLast;

    delete last;
}

int main()
{
    Node *head = nullptr;

    InsertFirst(head,30);
    InsertFirst(head,20);
    InsertFirst(head,10);

    InsertLast(head,40);
    InsertLast(head,50);

    cout<<"List: ";
    Display(head);

    DeleteFirst(head);

    cout<<"After DeleteFirst: ";
    Display(head);

    DeleteLast(head);

    cout<<"After DeleteLast: ";
    Display(head);

    return 0;
}