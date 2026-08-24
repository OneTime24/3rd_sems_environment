

#include <iostream>


using namespace std;


class stacks{
    public:
    int size;
    int top;
    int *s;

    stacks(){
        cout<<"Enter zie of the stack:";
        cin>>size;
        top=-1;
        s=new int[size];
    }

    void push(int x){

        if(top!=size-1){
        top++;
        s[top]=x;
        
    }else{
        cout<<"Stack OVerflowed: ";
    }

}
    int pop(){
        int rt=0;
        if(top==-1){
            cout<<"Stack Underflowed: ";
            return -1;
        }else{ 
            rt=s[top];
            top--;
            return rt;
            
        }
    }

    int peek(){
        if(top==-1){
            return -1;
        }else{
            return s[top];
        }
    }

    bool isEmpty(){
        return top==-1;
    }

    bool isFull(){
        return top==size-1;
    }
void display()
{
    if(isEmpty())
    {
        cout<<"Stack is empty\n";
        return;
    }

    cout<<"Top\n";
    for(int i=top;i>=0;i--)
    {
        cout<<s[i]<<endl;
    }
}
};


int main(){
    stacks s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(6);
    s1.pop();

    s1.display();
    
    cout<<s1.peek();
}