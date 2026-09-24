

#include <iostream>
using namespace std;


class node{
    public:
    int data;
    node *next;
    node *prev;

    node(int val){
        data=val;
        next=nullptr;
        prev=nullptr;

    }
};


class linkedl{
    private:

    node *curr;
    node *tail;
    node *head;
    int len;
    public:

    linkedl(){
        curr=nullptr;
        head=nullptr;
        tail=nullptr;
        len=0;
    }

    void insert(int pos, int val){

        // valid position

        node *n=new node(val);


        if(head==nullptr){
            n->next=n;
            n->prev=n;
            head=tail=n;
            len++;
            return ;
        }

        if(head==tail){
            curr=head;
            n->next=curr;
            n->prev=tail;
            curr->prev=n;
            head=n;
            len++;
            return ;
        }

        if(pos==len+1){

            curr=tail;

            curr->next=n;
            n->prev=curr;
            n->next=head;
            tail=n;
            len++;
            return ;
        }
        curr=head;
        for(int i=1;i<pos-1;i++){
            curr=curr->next;
        }

        n->next=curr->next;
        n->prev=curr;
        curr->next->prev=n;
        curr->next=n;
        len++;
        return ;
    }

void remove(int pos){

    if(pos==1){

        curr=head;
        head=head->next;

        head->prev=tail;
        tail->next=head;

        delete curr;
        len--;

        return;
    }

    if(pos==len){

        curr=tail;
        tail=tail->prev;

        tail->next=head;
        head->prev=tail;

        delete curr;
        len--;

        return;
    }

    curr=head;

    for(int i=1;i<pos-1;i++){
        curr=curr->next;
    }

    node *tmp=curr->next;

    curr->next=tmp->next;
    curr->next->prev=curr;

    delete tmp;
    len--;
}
    void traverse(){

        curr=head;

        if(head==nullptr){
            cout<<"No nodes available: \n";
        }
        do{
            cout<<curr->data<<" ";
            curr=curr->next;
        }while(curr!=head);
        cout<<endl;
    }
};


int main(){

    linkedl l1;
    l1.insert(1,10);

    l1.insert(2,20);

    l1.insert(3,30);

    l1.insert(4,40);

    l1.traverse();

    l1.remove(1);
    // l1.remove(2);

    l1.traverse();
}