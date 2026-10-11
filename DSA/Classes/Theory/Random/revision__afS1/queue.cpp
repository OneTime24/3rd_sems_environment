

#include <iostream>
using namespace std;


class queue{

    private:

    int *arr;
    int size;
    int noe;
    int front;
    int rear;

    public:

    queue(int sz){
        size=sz;
        arr=new int[sz];
        noe=0;
        front=0;
        rear=-1;
    }

    bool isfull(){
        if(noe==size){
            
            return true;
        }
        return false;
    }
    void enque(int val){

        if(isfull()){
            cout<<"STAC OVERFLOWED: "<<endl;
            return ;
        }

        if(rear==size-1){
            rear=0;
        }else{
            rear++;
        }

        arr[rear]=val;
        noe++;
    }
    bool isempty(){
        if(noe==0){
            return true;
        }
        return false;
    }

    int deque(){

        if(isempty()){
            cout<<"STACK UNDERFLOWED: "<<endl;
            return ;
        }
        
        int data=arr[front];
        
        if(front==size-1){
            front=0;
        }else{
            front++;
        }
        noe--;

        return data;

    }

    void peek(){
         if(isfull()){
            cout<<"STAC OVERFLOWED: "<<endl;
            return ;
        }
        if(isempty()){
            cout<<"STACK UNDERFLOWED: "<<endl;
            return ;
        }

        cout<<" "<<arr[front]<<endl;
    }
};
int main(){


}