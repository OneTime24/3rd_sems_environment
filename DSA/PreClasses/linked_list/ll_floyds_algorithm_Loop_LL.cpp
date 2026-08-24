

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void traversal(Node *head){
    Node *n=head;

    while(n!=nullptr){
        cout<<n->data<<" ";
        n=n->next;
    }
    cout<<endl;
}
void Insert(Node *&head, Node *&last,int pos, int x)
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


bool loop_detect(Node *head){
    Node *slow=head;
    Node *fast=head;

    while(fast!=nullptr && fast->next!=nullptr){

        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow){
            return true;
        }
    }
    return false;
}
int main(){

    Node *head1=new Node;
    head1=nullptr;
    Node *last1=new Node;
    last1=nullptr;

    Insert(head1,last1,0,1);

    Insert(head1,last1,1,2);

    Insert(head1,last1,2,3);

    Insert(head1,last1,3,4);

    Insert(head1,last1,4,5);


    cout<<loop_detect(head1);


}