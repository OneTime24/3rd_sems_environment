

#include <iostream>

using namespace std;


class Array{
    public:
    int *arry;
    int size;
    int leng;


    void inp(){
        cout<<"Enter values; ";

        for(int i=0;i<leng;i++){
            cin>>arry[i];
        }
    }

    void display(){
        for(int i=0;i<leng;i++){
            cout<<"\n-------------------\n"<<arry[i]<<" "<<endl;
        }
    }

    void del(){

        int ind;
        cout<<"Enter index of the value to delete: ";
        cin>>ind;


        for(int i=ind;i<leng-1;i++){

            arry[i]=arry[i+1];
        }

        leng--;

    }
};

int main(){

    Array arr;


    cout<<"Enter size of the array: ";

    cin>>arr.size;


    arr.arry=new int[arr.size];

    cout<<"Etner number of elemetns: ";

    cin>>arr.leng;

    arr.inp();

    arr.display();

    arr.del();

    arr.display();





}