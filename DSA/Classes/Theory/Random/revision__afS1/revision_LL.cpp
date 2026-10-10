


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

class linkedl{


    private:
    node *head=nullptr;
    node *curr;
    int len;

    public:

    linkedl(){
        len=0;
        curr=nullptr;
    }

    void insert(int pos, int val){

        node *t=new node(val);
        if(head==nullptr){
            t->next=nullptr;
            head=t;
            len++;
            return ;
        }

        if(pos==1){
            t->next=head;
            head=t;
            len++;
            return ;
        }

        if(pos==len+1){
            t->next=nullptr;
            curr=head;
            while(curr->next!=nullptr){
                curr=curr->next;
            }
            curr->next=t;
            len++;
            return ;
        }

        curr=head;
        for(int i=1;i<pos-1;i++){

            curr=curr->next;
        }
        t->next=curr->next;
        curr->next=t;
        len++;
        return ;

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

    l1.insert(1,5);
    l1.insert(3,35);

    l1.traverse();

}