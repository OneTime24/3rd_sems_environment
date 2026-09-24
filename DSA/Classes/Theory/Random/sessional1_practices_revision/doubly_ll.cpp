

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
    node *head;
    node *curr;
    node *tail;
    int len;


    public:

    linkedl(){
        head=nullptr;
        curr=nullptr;
        tail=nullptr;

        len=0;
    }

    void insert(int pos, int val){

        if(pos<1 || pos >len+1){
            cout<<"Invalid position : \n";
            return ;
        }
        node *n=new node(val);

        if(head==nullptr){
            n->next=nullptr;
            n->prev=nullptr;
            head=tail=n;
            len++;
            return ;
        }
    

        if(pos==1){
            curr=head;

            n->next=curr;
            n->prev=nullptr;
            curr->prev=n;
            head=n;
            len++;
            return ;
        }
        if(pos==len+1){
            curr=tail;
            n->next=nullptr;
            n->prev=curr;
            curr->next=n;
            tail=n;
            len++;
            return ;
        }

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

    node* get(int pos){
        curr=head;
        for(int i=1;i<pos;i++){
            curr=curr->next;
        }
        return curr;
    }

    void clear(){

        curr=head;

        while(curr!=nullptr){

            node *tmp=curr;
            curr=curr->next;
            delete tmp;
        }

        head=nullptr;
        tail=nullptr;
        len=0;
    }

    void remove(int pos){

        if(pos<1 || pos>len){
            cout<<"invalid position: "<<endl;
            return ;
        }

        if(head==tail){
            
            curr=head;
            curr->next=nullptr;
            curr->prev=nullptr;
            delete curr;
            len --;
            head=nullptr;
            tail=nullptr;
            return ;
            
        }

        if(pos==1){

        curr=head;
        head=head->next;
        head->prev=nullptr;
        delete curr;
        len--;
        return;
    }

        if(pos==len){
            curr=tail;
            curr->prev->next=nullptr;
            tail=tail->prev;
            delete curr;
            len--;
            return ;
            
        }
        curr=head;
        for(int i=1;i<pos;i++){

            curr=curr->next;
        }

        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
        delete curr;
        len--;
        return ;
    }



    void traverse(){
        curr=head;
        if(head==nullptr){
            cout<<"linked list is empty: \n";
            return ;
        }
        while(curr!=nullptr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }

};

int main(){


    linkedl l1;
    l1.insert(1,10);
    l1.insert(2,20);
    l1.insert(3,30);
    l1.insert(4,40);
    l1.insert(5,50);

    l1.traverse();

    l1.remove(1);

    l1.remove(4);
    l1.remove(2);

    l1.traverse();


}