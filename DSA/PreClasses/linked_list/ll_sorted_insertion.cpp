

#include <iostream>
using namespace std;

struct Node{

    int data;
    Node *next;
};

void sort_insert(Node *&head,int x){

    Node *t=new Node;
    t->data=x;
    t->next=nullptr;

    Node *p=head;
    Node *q=nullptr;


    while(p!=nullptr && p->data<x){

        q=p;
        p=p->next;
    }

    if(q==nullptr){
        t->next=head;
        head=t;
    }else{
        t->next=p;
        q->next=t;
    }

}


void traversal(Node *head){

    Node *n=head;
    while(n!=nullptr){
        cout<<n->data<<" ";
        n=n->next;
    }
}

int main(){

    Node *n1=new Node;
    n1->data=1;
    
    Node *head=n1;

    Node *n2=new Node;
    n2->data=2;
    n1->next=n2;

    Node *n3=new Node;
    n3->data=3;
    n2->next=n3;


    Node *n4=new Node;
    n4->data=4;
    n3->next=n4;


    traversal(head);
    sort_insert(head,0);
cout<<endl;
    traversal(head);

}