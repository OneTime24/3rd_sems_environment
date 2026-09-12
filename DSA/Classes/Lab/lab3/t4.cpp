#include <iostream>
using namespace std;

class node{
    public:

    int data;
    node *next;

    node(int val);
};

node::node(int val){
    data=val;
    next=nullptr;
}

node* build(int n){

    node *head=nullptr;
    node *last=nullptr;

    for(int i=0;i<n;i++){
        int val;
        cin>>val;

        node *n1=new node(val);

        if(head==nullptr){
            head=n1;
            last=n1;
        }
        else{
            last->next=n1;
            last=n1;
        }
    }

    return head;
}

node* mergi(node *a, node *b){          //iteratively

    node *c=nullptr;
    node *last=nullptr;

    if(a==nullptr) return b;
    if(b==nullptr) return a;

    if(a->data<=b->data){
        c=a;
        a=a->next;
    }
    else{
        c=b;
        b=b->next;
    }

    last=c;

    while(a!=nullptr && b!=nullptr){

        if(a->data<=b->data){
            last->next=a;
            last=a;
            a=a->next;
        }
        else{
            last->next=b;
            last=b;
            b=b->next;
        }
    }

    if(a==nullptr){
        last->next=b;
    }
    else{
        last->next=a;
    }

    return c;
}
node* merger(node *a, node *b){         //recursevely

    if(a==nullptr){
        return b;
    }

    if(b==nullptr){
        return a;
    }

    if(a->data<=b->data){

        a->next=merger(a->next,b);
        return a;
    }
    else{

        b->next=merger(a,b->next);
        return b;
    }
}

int main(){

    int n,m;
    cout<<"enter n and m: ";
    cin>>n>>m;

    cout<<"enter "<<n<<" elements for list a: ";
    node *a=build(n);

    cout<<"enter "<<m<<" elements for list b: ";
    node *b=build(m);

    node *c=mergi(a,b);

    cout<<"mergid list: ";

    if(c==nullptr){
        cout<<"EMPTY"<<endl;
        return 0;
    }
    while(c!=nullptr){
        cout<<c->data<<" ";
        c=c->next;
    }
    cout<<endl;

}