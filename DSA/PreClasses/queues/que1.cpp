

#include <iostream>
using namespace std;


class queue{
  
    private:
    int front;
    int rear;
    int size;
    int *q;

    public:

    queue(int size){
        front=rear=-1;
        this->size=size;
        q=new int[size];
    }


    bool isEmpty(){
        return front==-1;
    }
    bool isFull(){
        return (rear+1)%size==front;
    }

    void enqueue(int x){
        if(isEmpty()){
            front=rear=0;
            q[rear]=x;
        }else if(isFull()){
                cout<<"Overflow!!";
        }else{
            rear=(rear+1)%size;
            q[rear]=x;
        }
    }

    int dequeue(){
        int x=0;
        if(front==-1){

            cout<<"Queue Underflowed: ";
        }else if(front==rear){
            x=q[front];
            front=rear=-1;
            cout<<"Queue empty now: ";
        }else{
            x=q[front];
            front=(front+1)%size;
        }
        return x;
    }
    void traverse(){
            if(isEmpty())
    {
        cout<<"Queue is Empty\n";
        return;
}
        int i=front;
        while(true){
            cout << q[i] << " ";

            if(i == rear)
                break;

            i = (i + 1) % size;
                }
    }
        ~queue()
    {
        delete[] q;
    }
};
int main(){

 
    queue q1(5);

    q1.enqueue(1);
    q1.enqueue(2);

    q1.enqueue(3);
    q1.enqueue(4);

    q1.enqueue(5);
    // q1.enqueue(6);

    // q1.enqueue(7);
    // q1.enqueue(8);

    q1.traverse();
    
}