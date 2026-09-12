#include <iostream>
using namespace std;

class node{
    public:

    int id;
    node *next;

    node(int val);
};

node::node(int val){
    id=val;
    next=nullptr;
}

int josephus(int n, long long k){

    node *head=new node(1);
    node *last=head;

    for(int i=2;i<=n;i++){
        node *n1=new node(i);
        last->next=n1;
        last=n1;
    }
    last->next=head;

    node *prev=last;
    node *curr=head;
    int remaining=n;

    while(remaining>1){

        int steps=(k-1)%remaining;

        for(int i=0;i<steps;i++){
            prev=curr;
            curr=curr->next;
        }

        node *dead=curr;
        prev->next=curr->next;
        curr=prev->next;

        delete dead;
        remaining--;
    }

    int ans=curr->id;
    delete curr;
    return ans;
}

int main(){

    cout<<"Enter number of rounds to test: ";
    int t;
    cin>>t;

    for(int tc=1;tc<=t;tc++){
        cout<<"Enter value of N and K: ";
        int n;
        long long k;
        cin>>n>>k;

        cout<<"Case "<<tc<<": "<<josephus(n,k)<<"\n";
    }

}