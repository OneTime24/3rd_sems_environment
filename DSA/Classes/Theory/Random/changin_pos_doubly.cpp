



#include <iostream>
using namespace std;

class node{
    public:

    int data;
    node *next;
    node *prev;

    node(int val){
        data= val;
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

        if(pos<1 || pos>len+1){
            cout<<"invalid address\n";
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

        curr=head;
        for(int i=1;i<pos-1;i++){
            curr=curr->next;
        }

        n->next=curr->next;
        n->prev=curr;
        n->next->prev=n;
        curr->next=n;
        len++;

    }


     node* remove(int pos){

        if(pos<1 || pos>len){
            cout <<"invalid position: \n";
            return nullptr;
        }

        if(head==nullptr){
            cout<<"nothing to remove: ";
            return nullptr;
        }
        if(head==tail){
            curr=head;
            head=nullptr;
            tail=nullptr;

            len--;
            return curr;
        }

        if(pos==1){

            curr=head;

            
            head=head->next;
            head->prev=nullptr;

            len --;
            return curr;

        }
        if(pos==len){
            curr=tail;

            tail=tail->prev;
            tail->next=nullptr;

            len--;
            return curr;
        }

        curr=head;
        for(int i=1;i<pos-1;i++){
            curr=curr->next;
        }
        node *tmp=curr->next;
        curr->next=tmp->next;
        tmp->next->prev=curr;

        len --;
        return tmp;
     }

     void change_pos(int pos1,int pos2){

         if(pos1<1 || pos1>len || pos2<1 || pos2>len){
        cout<<"invalid position\n";
        return;
    }
        node *rmn=remove(pos1);

        // if(pos1<pos2){
        //     len--;
        // }
        if(pos2==1){
            rmn->next=head;
            rmn->prev=nullptr;
            head->prev=rmn;
            head=rmn;
            len++;
            return ;
        }
if(pos2==len+1){   // fixed: after remove, original last position becomes len+1

        curr=tail;

        rmn->next=nullptr;
        rmn->prev=tail;
        tail->next=rmn;
        tail=rmn;
        len++;
        return ;
    }

        curr=head;
        for(int i=1;i<pos2-1;i++){
            curr=curr->next;
        }

        rmn->next=curr->next;
        rmn->prev=curr;
        curr->next->prev=rmn;
        curr->next=rmn;
        len++;

     }
    void traverse(){
        curr=head;

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

    l1.traverse();

    l1.change_pos(1,4);

    l1.traverse();
}