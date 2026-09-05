

#include <iostream>
using namespace std;


class arrayt{

    private:

        int *arr;
        int size;
        int len;
        int *curr;

    public:

    arrayt(int size){
        this->size=size;
        arr=new int[size];
        len=0;
        curr=nullptr;
    }


    void start(){
        curr=arr;

    }
    void insert(int x, int val){
        
        for(int i=x;i<len;i++){
            *(curr+i)=*(curr+i-1);
        }
        *(curr+x)=val;
        len++;
    }

    void append(int val){

        *(curr+len)=val;
        len++;
    }

    void del(int pos){

        for(int i=len;i>=pos;i--){
            *(curr+i)=*(curr+i+1);

        }
        len--;
    }

    ~arrayt(){
        delete []arr;
        curr =nullptr;
        // delete curr;
    }

    void display(){
        for(int i=0;i<len;i++){
            cout<<"Array Value: "<<*(arr+i)<<endl; 
        }
    }

};


int main(){
    arrayt a(10);
    a.start();
    a.append(20);

    a.append(30);

    a.append(40);

    a.append(50);

    a.append(60);

    a.insert(2,35);

    a.display();


}