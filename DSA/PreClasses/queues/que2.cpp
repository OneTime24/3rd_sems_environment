#include <iostream>
using namespace std;

struct Node{

    int data;
    Node *next;
};

Node *front=nullptr;
Node *rear=nullptr;


void enque(int x){

    Node *p;
    p=new Node;
    p->data=x;
    p->next=nullptr;
    if(front==nullptr){
        front=rear=p;
        
    }else{
        rear->next=p;
        rear=p;
    }
}

int deque(){
    int x=0;
    if(front==nullptr){
        cout<<"Queue Underflowed: ";
    }else if(front==rear){
        x=front->data;
        cout<<"Queue Emptied: ";
        front=nullptr;
        rear=nullptr;
    }else{
        Node *t=front;
        x=t->data;
        front=front->next;
        
    delete t;   
    }
    return x;
}

void traverse(){
    Node *p=front;
    while(p!=nullptr){
        cout<<p->data<<" ";
        p=p->next;
    }
}
int main(){

    enque(1);

    enque(2);

    enque(3);

    enque(4);

    traverse();
    cout<<"Deleted "<<deque()<<endl;
    cout<<"Deleted "<<deque()<<endl;
    traverse();


}