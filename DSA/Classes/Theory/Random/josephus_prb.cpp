

#include <iostream>
using namespace std;


class node{
    public:
    int data;
    node *next;

    node(int val){
        data=val;
        next=nullptr;
    }
};


int josephus(int n, int k){

    node *head=new node(1);
    node *curr=head;

    for(int i=2;i<=n;i++){
        curr->next=new node(i);
        curr=curr->next;
    }

    curr->next=head;

    curr=head;

    while(curr->next!=curr){

        for(int i=1;i<k-1;i++){
            curr=curr->next;
        }
        node *tmp=curr->next;
        curr->next=tmp->next;
        delete tmp;

        curr=curr->next;
    }

    int data=curr->data;
    return data;
};



int main(){

    cout<<josephus(7,3);
}