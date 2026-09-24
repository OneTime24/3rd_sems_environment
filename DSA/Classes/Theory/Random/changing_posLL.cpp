
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
        len=0;
        tail=nullptr;
        curr=nullptr;
    }


    void insert(int pos, int val){
        

        node *n=new node(val);


        if(head==nullptr){
            n->prev=nullptr;
            n->next=nullptr;
            head=tail=n;
            len++;
            return ;
        }
        if(pos==1){
            n->prev=nullptr;
            n->next=head;
            head->prev=n;
            head=n;
            len++;
            return ;
        }
        if(pos ==len+1){

            curr=tail;
            n->next=nullptr;
            curr->next=n;
            n->prev=curr;
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

    void display(){

        curr=head;

        while(curr!=nullptr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }

    node* remove(int pos){

        if(pos==1){
            curr=head;

            head=head->next;
            if(head!=nullptr)
                head->prev=nullptr;
            len--;
            return curr;
        }
        if(pos==len){

            curr=tail;

            node *tmp=curr->prev;
            tmp->next=nullptr;
            tail=tmp;
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
        len--;
        return tmp;
        

    }

    void change_pos(int pos1, int pos2){

     node *rmn=remove(pos1);

    if(pos1<pos2)
        pos2--;

    if(pos2==1){

        rmn->next=head;
        rmn->prev=nullptr;

        head->prev=rmn;
        head=rmn;

        len++;
        return;
    }

    curr=head;

    for(int i=1;i<pos2-1;i++)
        curr=curr->next;

    rmn->next=curr->next;
    rmn->prev=curr;

    curr->next->prev=rmn;
    curr->next=rmn;

    len++;
    }
};


int main(){


    linkedl l1;
    l1.insert(1,10);
    l1.insert(2,20);
    l1.insert(3,30);
    l1.insert(4,40);

    l1.display();

    l1.change_pos(4,1);

    l1.display();
}