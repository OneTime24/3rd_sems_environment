

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


    // heapify up : max heap
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

    // heapify down : Max Heap
    int deletion(){
        if(size==0){
            return -1;
        }
        int deleted=heap[1];

        heap[1]=heap[size];
        
        size--;

        int i=1;

        while(true){

            int lft=2*i;
            int rgt=2*i+1;

            int largest=i;
            

            if(lft<=size && heap[lft]>heap[largest]){
                largest=lft;
            }
            if(rgt<=size && heap[rgt]>heap[largest]){
                largest=rgt;
            }

            if (largest==i){
                break ;
            }

            swap(heap[i],heap[largest]);
            i=largest;
        }

        return deleted;
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