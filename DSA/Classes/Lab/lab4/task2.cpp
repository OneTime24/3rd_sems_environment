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

class stack{

    private:

    node *top;
    int len;

    public:

    stack(){
        top=nullptr;
        len=0;
    }

    bool isEmpty(){
        return top==nullptr;
    }

    void push(int val){
        node *n=new node(val);
        n->next=top;
        top=n;
        len++;
        cout<<"pushed: "<<val<<endl;
    }

    void pop(){
        if(isEmpty()){
            cout<<"Underflow!! stack is empty\n";
            return ;
        }
        node *tmp=top;
        cout<<"popped: "<<tmp->data<<endl;
        top=top->next;
        delete tmp;
        len--;
    }

    void peek(){
        if(isEmpty()){
            cout<<"stack is empty\n";
            return ;
        }
        cout<<"top element: "<<top->data<<endl;
    }

    void display(){
        if(isEmpty()){
            cout<<"stack is empty\n";
            return ;
        }
        node *curr=top;
        cout<<"stack: ";
        while(curr!=nullptr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }

    // linked list has no fixed cap so isFull is always false,
    // but menu still needs the option
    bool isFull(){
        return false;
    }

    ~stack(){
        while(top!=nullptr){
            node *tmp=top;
            top=top->next;
            delete tmp;
        }
    }
};


int main(){

    stack s1;
    int ch,val;

    while(true){

        cout<<"\n1. Push   2. Pop   3. Peek   4. Display   5. isEmpty   6. isFull   7. Exit\n";
        cout<<"enter choice: ";
        cin>>ch;

        if(ch==1){
            cout<<"enter value: ";
            cin>>val;
            s1.push(val);
        }
        else if(ch==2){
            s1.pop();
        }
        else if(ch==3){
            s1.peek();
        }
        else if(ch==4){
            s1.display();
        }
        else if(ch==5){
            if(s1.isEmpty())
                cout<<"stack is empty\n";
            else
                cout<<"stack is not empty\n";
        }
        else if(ch==6){
            if(s1.isFull())
                cout<<"stack is full\n";
            else
                cout<<"stack is not full (linked list grows dynamically)\n";
        }
        else if(ch==7){
            cout<<"exiting...\n";
            break;
        }
        else{
            cout<<"invalid choice\n";
        }
    }

}