


#include <iostream>

using namespace std;


struct Node{
    int data;
    Node *next;
};


void insert(Node *&head){

    Node *t=new Node;
    t->data=5;

    int pos=0;

    if(pos==0){
 
       t->next=head;
       head=t;
}else{
    Node *p=head;

    for(int i=0;i<pos-1 && p!=nullptr;i++){

        p=p->next;
        
    }

    if(p!=nullptr){

    t->next=p->next;
    p->next=t;

    }
}

}

void display(Node *head){

    Node *p=head;

    while(p!=nullptr){
        cout<<p->data<<" ";
        p=p->next;
    }
}



int main(){

    Node *n1=new Node;
    n1->data=1;


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

    Node *head = n1;

    display(head);
    cout<<"\n\n";
    insert(head);
    cout<<"\n\n";
    display(head);



}