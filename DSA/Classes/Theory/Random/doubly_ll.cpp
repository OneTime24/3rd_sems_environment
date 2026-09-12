

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


class linked{

    private:
    int len;
    node *head;
    node *curr;

    public:

    linked(){
        len=0;
        head=nullptr;
        curr=nullptr;
    }

    void insert(int pos, int val){

        node *n=new node(val);
        curr=head;
        if(pos==1){
            n->next=head;
            if(head!=nullptr){
                head->prev=n;
            }

            head=n;
            len++;
        }else{

            for(int i=1;i<pos-1;i++){
                curr=curr->next;
            }

            n->next=curr->next;
            if(curr->next!=nullptr){
                curr->next->prev=n;
            }
            curr->next=n;
            len++;
        }
    }


    void remove(int pos){
        curr=head;
        if(pos==1){
            head=head->next;
            if(head!=nullptr){
                head->prev=nullptr;
        }
        delete curr;
    }else{

        for(int i=1;i<pos-1;i++){
            curr=curr->next;
        }

        node *tmp=curr->next;
        curr->next=tmp->next;
        
        if(tmp->next!=nullptr){
            tmp->next->prev=curr;
        }
        delete tmp;
    }
}
node* get_pos(int pos)
{
    curr = head;

    if(pos == 1)
    {
        return curr;
    }

    for(int i = 1; i < pos; i++)
    {
        curr = curr->next;
    }

    return curr;
}
void change_pos(int pos1, int pos2)
{
    if(pos1 == pos2)
        return;

    node* b_pos = get_pos(pos1);

    // Remove b_pos

    if(b_pos->prev != nullptr)
        b_pos->prev->next = b_pos->next;
    else
        head = b_pos->next;

    if(b_pos->next != nullptr)
        b_pos->next->prev = b_pos->prev;


    // Position changes after removal
    if(pos1 < pos2)
        pos2--;


    // Insert at position 1

    if(pos2 == 1)
    {
        b_pos->prev = nullptr;
        b_pos->next = head;

        if(head != nullptr)
            head->prev = b_pos;

        head = b_pos;
    }

    // Insert somewhere after position 1

    else
    {
        node* curr = get_pos(pos2 - 1);

        b_pos->next = curr->next;
        b_pos->prev = curr;

        if(curr->next != nullptr)
            curr->next->prev = b_pos;

        curr->next = b_pos;
    }
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


    linked l1;

    l1.insert(1,10);
    l1.insert(2,20);
    l1.insert(3,30);
    l1.insert(4,40);
    l1.insert(5,50);

    l1.traverse();
    l1.remove(1);
    l1.remove(2);
    l1.traverse();
}