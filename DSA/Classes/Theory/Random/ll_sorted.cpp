

#include <iostream>
using namespace std;


class node{

    public:

    int data;
    node *next;

    node(int v){
        data=v;
        next=nullptr;
    }
};

class linkedl{

    private:
    node *head;
    node *tail;
    node *curr;
    int len;


    public:
    linkedl(){
        head=tail=nullptr;
        len=0;
    }

    void insert(int pos ,int val){

        node *n=new node(val);
        
        node *p;
        node *q;

        if(head==nullptr){
            head=tail=n;
            len++;
            return ;
        }

        p=head;
        q=nullptr;


        while(p!=nullptr && p->data<val){
            q=p;
            p=p->next;
        }

        if(q==nullptr){
            n->next=head;
            head=n;
            len++;
            return ;
        }else{
            n->next=p;
            q->next=n;
            len++;
        }



        // }else if(pos==len+1){
        //     n->next=nullptr;
        //     tail->next=n;
        //     tail=n;
        //     len++;
        // }else{
        //     node *curr=head;

        //     for(int i=1;i<pos-1;i++){
        //         curr=curr->next;
        //     }

        //     n->next=curr->next;
        //     curr->next=n;
        //     len++;
        // }
    }

    void traverse(){
        curr=head;

        while(curr!=nullptr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
    }
};

int main(){

    linkedl l1;

    l1.insert(1,10);

    l1.insert(2,20);

    l1.insert(3,30);

    l1.insert(4,40);
    l1.traverse();
}