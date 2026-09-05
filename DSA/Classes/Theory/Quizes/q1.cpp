

#include <iostream>
using namespace std;


class arra{
    public:
    int *arr;
    int *curr;
    int size;
    int len;

    arra(int sz){
        size=sz;
        arr=new int[sz];
        curr=nullptr;
    }

    void insertvalid(int pos,int val){

        if(len==size){
            cout<<"Size is full"<<endl;
        }

        curr=arr+pos-1;

        for(int i=pos;i<=len;i++){

            *(curr+1)=*curr;
            curr++;
        }
        len++;
    }


};

int main(){

    arra a1(10);

    a1.insertvalid(1,10);

    a1.insertvalid(2,20);

    a1.insertvalid(3,30);

    a1.insertvalid(4,40);
}