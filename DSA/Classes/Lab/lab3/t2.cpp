

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
    int len;

    public:
    linkedl(){
        head=nullptr;
        len=0;
    }

    void insert(int pos, int val){

        if(pos<1 || pos>len+1){
            cout<<"Invalid position: ";
            return ;
        }
        node *n=new node(val);

        if(pos==1){
            n->next=head;
            head=n;
            len++;
            return ;
        }
        
        
        node *curr=head;    
        for(int i=1;i<pos-1;i++){
            curr=curr->next;
        }
        n->next=curr->next;
        curr->next=n;
        len++;

    }

    bool remove(int x){

        node *curr=head;

        if(head==nullptr){
            return false;
        }
        if(head->data==x){
            node *tmp=head;
            head=head->next;
            
            delete tmp;
            len--;
            return true;
        }

        while(curr->next!=nullptr){

            if(curr->next->data==x){
                node *tmp=curr->next;

                curr->next=tmp->next;
                delete tmp;
                len--;
                return true;
            }
            curr=curr->next;
        }

        return false;
    }

    void display(){

        node *curr=head;
        if(head==nullptr){
        cout<<"EMPTY"<<endl;
        return ;
    }
        while(curr!=nullptr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }

    void reverse(){

        node *curr=head;
        node *next=nullptr;
        node *prev=nullptr;

        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }
};

int main(){

    linkedl l1;

    int x;
    cin>>x;

    for(int i=1;i<=x;i++){

        int y;
        cin>>y;

        l1.insert(i,y);
    }


    int n;
    cin>>n;

    for(int i=1;i<=n;i++){

        char op;
        cin>>op;

        if(op=='I'){

            int val,pos;
            cin>>val>>pos;

            l1.insert(pos,val);

        }else if(op=='D'){

            int val;
            cin>>val;

            l1.remove(val);

        }else if(op=='R'){

            l1.reverse();
        }
    }

    l1.display();

}