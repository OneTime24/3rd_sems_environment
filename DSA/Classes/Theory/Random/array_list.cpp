

#include <iostream>
using namespace std;


class arra{
    private:
    int *arr;
    int *arr2;
    int size;
    // int *curr;
    int len;

    public:

    arra(int sz){
        size=sz;
        arr=new int[size];
        arr2=nullptr;
        len=0;

    }


    void add(int val){
        *(arr+len)=val;
        len++;
    }
    void remove(int pos){
        
        for (int i=pos;i<len-1;i++){
            *(arr)=*(arr-1);

        }
        len--;
    }

    void insert(int pos,int val){
        if(pos>0 && pos<size){
        for(int i=pos;i<len;i++){
            *(arr+1)=*(arr);
        }

        *(arr+pos)=val;
        len++;
    }
    }

    void findx(int val){
        int flg=0;
        
        for(int i=0;i<len;i++){
            if (*(arr+i)==val){
                flg=1;
            }
        }

        if(flg==1){
            cout<<"FOUUND"<<endl;
        }else{
            cout<<"NOT FOUND: ";
        }
    }

    void copy(int sz){
        if(sz>=size){
            arr2=new int[sz];
            for(int i=0;i<len;i++){
                *(arr2+i)=*(arr+i);
            }
        }

    }

    void display(arra obj){
        for(int i=0;i<obj.len;i++){
            cout<<"Value: "<<*(obj.arr+i)<<endl;
        }
    }
};

int main(){

    arra a1(10);
    a1.add(1);
    a1.add(2);
    a1.add(3);
    a1.add(4);
    a1.add(5);
    a1.add(6);

    a1.copy(9);
    a1.display(a1);
}