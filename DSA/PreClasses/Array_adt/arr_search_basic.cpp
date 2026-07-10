

#include <iostream>
using namespace std;


struct Array{

    int *ary;
    int size;
    int leng;
};


void inp(Array ptr){

    cout<<"Enter values: ";
    for(int i=0;i<ptr.leng;i++){
        cin>>ptr.ary[i];
    }
}

void disp(Array arr){
    cout<<"\n-----------------------------------\n";
    for(int i=0;i<arr.leng;i++){
        cout<<arr.ary[i]<<" ";
    }
}

int search(Array arr){
    cout<<"Enter value to find index of it: ";
    int key;
    cin>>key;

    for(int i=0;i<arr.leng;i++){

        if(key==arr.ary[i]){
            return i;
        }
        
    }
    return -1;
}

int main(){


    Array arr;


    cout<<"Enter array size: ";
    cin>>arr.size;
    arr.ary=new int[arr.size];

    cout<<"Enter number of elemetns: ";
    cin>>arr.leng;

    inp(arr);

    disp(arr);

    int x=search(arr);

    if(x==-1){
        cout<<"Search Failed: ";

    }else{
        cout<<"Value found at Index: "<<x<<endl;
    }
}