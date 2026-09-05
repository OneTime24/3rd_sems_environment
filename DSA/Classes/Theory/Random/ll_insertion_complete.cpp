

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

class linkedlist{

    private:
    node *head;
    node *tail;
    int len;

    public:

    linkedlist(){
        head=nullptr;
        tail=nullptr;
        len=0;
    }

    void insert(int pos,int val){
        node *n=new node(val);

        if(pos==1){
            n->next=head;
            head=n;
            len++;
            tail=n;
        }else if(pos==len+1){
            n->next=nullptr;
            tail->next=n;
            tail=n;
            len++;
            
        }else{
            node *curr=head;

            for(int i=1;i<pos-1;i++){
                curr=curr->next;
            }

            n->next=curr->next;
            curr->next=n;

        }

    
    }

    void traverse(){
        node *curr=head;
        while(curr!=nullptr){
            cout<<curr->data<<" ";
                curr=curr->next;
        }
    }


    ~linkedlist(){
        node *curr=head;

        while(curr!=nullptr){
            
            node *tmp=curr;
            curr=curr->next;
            delete tmp;
        }
    }




};


int main(){

    linkedlist l1;
    l1.insert(1,10);
    l1.insert(2,20);
    l1.insert(3,30);

    l1.traverse();
    l1.insert(1,10);
    l1.insert(2,20);
    l1.insert(3,30);

    l1.traverse();

}