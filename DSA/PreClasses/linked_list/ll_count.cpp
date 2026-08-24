

#include <iostream>
using namespace std;


struct Node{
    int data;
    Node *next;
};


int count(Node *head){

    Node *n=head;
    int cnt=0;
    while(n!=nullptr){
       cnt++;
        n=n->next;
    }
    return cnt;
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

    cout<<"number of nodes: "<<count(head);


    

    
    
    
}