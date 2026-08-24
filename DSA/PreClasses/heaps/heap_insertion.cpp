

#include <iostream>
using namespace std;


class Heap{
    private:

    int heap[100];
    int size;

    public:

    Heap(){
        size=0;
    }


    void heap_insert(int val){
        size++;
        int i=size;

        while(i>1 && val>heap[i/2]){
            heap[i]=heap[i/2];
            i/=2;

            heap[i]=val;
        }
    }
    void display(){
        for (int i=1;i<=size;i++){
            cout<<heap[i]<<" ";
        }
    }
};



int main(){

    Heap h1;

    h1.heap_insert(10);
    h1.heap_insert(20);
    h1.heap_insert(30);
    h1.heap_insert(40);
    h1.heap_insert(50);
    h1.heap_insert(60);
    h1.display();
}