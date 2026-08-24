

#include <iostream>
using namespace std;


struct Node{
    int data;
    Node *next;
};


int max(Node *head){

    Node *n=head;
    int max=n->data;
    while(n!=nullptr){
        if(n->data>max)
            max=n->data;
        n=n->next;
    }
    return max;
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

    n4->next=nullptr;

    cout<<"max of nodes: "<<max(head);


    

    
    
    
}