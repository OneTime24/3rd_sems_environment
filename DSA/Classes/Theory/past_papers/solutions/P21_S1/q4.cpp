// Q. 4) Consider that Singly Link List (SLL) of some nodes, filled with integer data exists in memory. Write 2
// program that tells how many values are repeated in SLL. 17]


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

    int repeated(){

    int count=0;
    node *curr=head;

    while(curr!=nullptr){

        bool already=false;
        node *check=head;

        while(check!=curr){

            if(check->data==curr->data){
                already=true;
                break;
            }

            check=check->next;
        }

        if(!already){

            node *temp=curr->next;

            while(temp!=nullptr){

                if(temp->data==curr->data){
                    count++;
                    break;
                }

                temp=temp->next;
            }
        }

        curr=curr->next;
    }

    return count;
}

void display(){

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

    l1.insert(3,10);

    l1.insert(4,30);

    l1.insert(5,20);

    l1.insert(6,10);


    l1.display();

    int cnt=l1.repeated();

    cout<<endl<<cnt<<endl;
}