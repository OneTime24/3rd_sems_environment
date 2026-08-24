

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};
Node *top=nullptr;

void push(int x){
    Node *t=new Node;

    if(t==nullptr){
        cout<<"Stack OVerflowed: ";

    }else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop(){
    if(top==nullptr){
        cout<<"Stack Underflowed: ";
        return -1;
    }

    Node *p=top;
    int x=p->data;

    top=top->next;
    delete p;

    return x;
}


int peek(){
    if(top==nullptr){
        return -1;
    }else{
        return top->data;
    }
}

bool isEmpty(){

    return top==nullptr;
}

void traverse(Node *he){
    Node *p=he;

    while(p!=nullptr){
        cout<<p->data<<" ";
        p=p->next;
    }
}


int main(){


    push(7);

    push(8);

    push(9);

    push(10);
    push(11);
    push(12);

    traverse(top);
    cout<<endl;

    pop();
    
    traverse(top);

    
}