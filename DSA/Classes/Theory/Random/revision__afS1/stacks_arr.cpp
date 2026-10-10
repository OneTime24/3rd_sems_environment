


#include <iostream>
using namespace std;


class arra{

    private:
    int *arr;
    int sz;
    int len;
    int top=-1;
    public:
    arra(int size){
        arr=new int[size];
        sz=size;
        len=0;
    }

        void push(int x){

        if(top!=sz-1){
        top++;
        arr[top]=x;
        
    }else{
        cout<<"Stack OVerflowed: ";
    }

}
    int pop(){
        int da=0;

        if(top==-1){
            cout<<"STACK UNDERFLOWED: ";
            return -1;
        }else{
            da=arr[top--];
            return da;
        }

    }
    void isfull(){
        if(top==sz-1){
            cout<<"STACK OVERFLOWED: "<<endl;
        }

    }

    void isempty(){
        if(top==-1){
            cout<<"STACK UNDERFLOWED: "<<endl;
        }
    }

    void peek(){
         if(top == -1){
        cout << "Stack is empty" << endl;
    }else{
        cout << arr[top] << endl;
    }
    }
    ~arra(){
       
        delete[] arr;
    }
};
int main(){

    arra stk(10);

    stk.isempty();
    stk.push(1);

    stk.push(2);

    stk.push(3);

    stk.push(4);

    stk.peek();
    cout<<stk.pop()<<" "<<endl;


}