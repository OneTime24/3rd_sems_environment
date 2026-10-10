

#include <iostream>
using namespace std;



struct Node{
    int data;
    Node *next;
};
// Node *head=nullptr;
// Node *last=nullptr;
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

Node* merge(Node *first, Node *second){

    Node *third=nullptr;
    Node *last=nullptr;


    if(first->data <second->data){
        third=last=first;
        first=first->next;
    }else{
        third=last=second;
        second=second->next;
    }

    last->next=nullptr;

    while(first!=nullptr && second!=nullptr){

        if(first->data<second->data){

            last->next=first;
            last=first;
            first=first->next;

        }else{

            last->next=second;
            last=second;
            second=second->next;

        }
        last->next=nullptr;
    }

    if(first!=nullptr){
        last->next=first;
    }else{
        last->next=second;
    }

    
    return third;
}
int main(){

        Node *head1=new Node;
    head1=nullptr;
    Node *last1=new Node;
    last1=nullptr;
    Node *head2=new Node;
    head2=nullptr;
    Node *last2=new Node;

    last2=nullptr;

    Insert(head1,last1,0,1);
    Insert(head1,last1,1,2);
    Insert(head1,last1,2,3);
    Insert(head1,last1,3,4);


    Insert(head2,last2,0,1);
    Insert(head2,last2,1,2);
    Insert(head2,last2,2,3);
    Insert(head2,last2,3,4);


    traversal(head1);

    traversal(head2);

    Node *merged=merge(head1,head2);

    traversal(merged);

}