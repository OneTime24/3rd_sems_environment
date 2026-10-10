

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
    node *head;
    node *top;
    
    public:

    stack(){
        head=nullptr;
        top=head;
    }
    void push(int val){

        node *t=new node(val);

        t->next=head;
        head=t;
        // top=head;
    }

    void pop() {
    if (head == nullptr) {
        cout << "Stack Underflow" << endl;
        return;
    }

    node *tmp = head;
    head = head->next;
    delete tmp;
}

    void peek(){
          if (head == nullptr) {
        cout << "Stack is empty" << endl;
        return;
    }

    cout << head->data << endl;
    }
};
int main(){

    stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    s1.peek();
    s1.pop();
    s1.peek();
    s1.pop();
    s1.peek();
    s1.pop();
    s1.peek();
    s1.pop();
    
}