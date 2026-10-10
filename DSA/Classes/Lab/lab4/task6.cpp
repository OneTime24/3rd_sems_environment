#include <iostream>
using namespace std;

class twostacks{

    private:

    int *arr;
    int n;
    int top1;
    int top2;

    public:

    twostacks(int size){
        n=size;
        arr=new int[n];
        top1=-1;      // stack1 grows from index 0 upward
        top2=n;       // stack2 grows from index n-1 downward
    }

    void push1(int val){

        if(top1+1==top2){
            cout<<"Overflow!! stack1 is full\n";
            return ;
        }
        top1++;
        arr[top1]=val;
    }

    void push2(int val){

        if(top1+1==top2){
            cout<<"Overflow!! stack2 is full\n";
            return ;
        }
        top2--;
        arr[top2]=val;
    }

    int pop1(){

        if(top1==-1){
            cout<<"Underflow!! stack1 is empty\n";
            return -1;
        }
        int val=arr[top1];
        top1--;
        return val;
    }

    int pop2(){

        if(top2==n){
            cout<<"Underflow!! stack2 is empty\n";
            return -1;
        }
        int val=arr[top2];
        top2++;
        return val;
    }

    void display(){

        cout<<"stack1: ";
        for(int i=top1;i>=0;i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;

        cout<<"stack2: ";
        for(int i=top2;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    ~twostacks(){
        delete[] arr;
    }
};


int main(){

    twostacks ts(6);

    ts.push1(1);
    ts.push1(2);
    ts.push1(3);

    ts.push2(10);
    ts.push2(20);
    ts.push2(30);

    ts.display();

    // this should overflow since array is full now (6 elements in size 6)
    ts.push1(4);

    cout<<"popped from stack1: "<<ts.pop1()<<endl;
    cout<<"popped from stack2: "<<ts.pop2()<<endl;

    ts.display();

}