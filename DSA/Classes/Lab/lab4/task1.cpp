#include <iostream>
using namespace std;

class stack{

    private:

    int arr[10];
    int top;
    int cap;

    public:

    stack(){
        top=-1;
        cap=10;
    }

    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top==cap-1;
    }

    void push(int val){
        if(isFull()){
            cout<<"Overflow!! stack is full\n";
            return ;
        }
        top++;
        arr[top]=val;
        cout<<"pushed: "<<val<<endl;
    }

    void pop(){
        if(isEmpty()){
            cout<<"Underflow!! stack is empty\n";
            return ;
        }
        cout<<"popped: "<<arr[top]<<endl;
        top--;
    }

    void peek(){
        if(isEmpty()){
            cout<<"stack is empty\n";
            return ;
        }
        cout<<"top element: "<<arr[top]<<endl;
    }

    void display(){
        if(isEmpty()){
            cout<<"stack is empty\n";
            return ;
        }
        cout<<"stack: ";
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
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
                cout<<"stack is not full\n";
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