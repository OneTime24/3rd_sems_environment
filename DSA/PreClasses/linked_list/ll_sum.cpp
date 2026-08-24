

#include <iostream>
using namespace std;


struct Node{
    int data;
    Node *next;
};


int sum(Node *head){

    Node *n=head;
    int sum=0;
    while(n!=nullptr){
       sum+=n->data;
        n=n->next;
    }
    return sum;
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

    cout<<"sum of nodes: "<<sum(head);


    

    
    
    
}