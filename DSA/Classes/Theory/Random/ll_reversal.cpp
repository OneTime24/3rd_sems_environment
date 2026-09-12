

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
    }

    void traverse(){
        curr=head;

        while(curr!=nullptr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
    }

    
    void recurs_rev(node *q, node *p){

        if(p!=nullptr){
            recurs_rev(p,p->next);
            p->next=q;
        }else{
            head=q;
        }
    }
    node *reverse(){

        node *prev=nullptr;
        curr=head;
        
        recurs_rev(prev,curr);

        // while(curr!=nullptr){

        //     next=curr->next; // save the chain
        //     curr->next=prev;       //reverse the chain
        //     prev=curr;              //move the prev pointer one ahead
        //     curr=next;          //move curr to the next
        // }
        // head=prev;
        return head;

    }

    void del(int pos){

        node *p=head;
        node *q=nullptr;
        if(pos==1){
            head=head->next;
            delete p;
            len--;
            return ;
        }

        for(int i=1;i<pos-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        delete p;
        len--;
    }
};

int main(){

    linkedl l1;

    l1.insert(1,10);

    l1.insert(2,20);

    l1.insert(3,30);

    l1.insert(4,40);
    l1.traverse();

    // l1.del(4);
    // l1.del(1);

    // cout<<"\n____________________________________\n";
    // l1.traverse();


    node *revl1=l1.reverse();

    cout<<"\n____________________________________\n";
    
    while(revl1 != nullptr){
            cout << revl1->data << " ";
            revl1 = revl1->next;
        }




}