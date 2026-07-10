

#include <iostream>
using namespace std;


struct Array{
    int *ary;
    int leng;
    int size;
};


void disp(Array arr){
    cout<<"\n----------------------\n";
    for(int i=0;i<arr.leng;i++){
        cout<<arr.ary[i]<<endl;
    }

    cout<<"\n----------------------\n";
}

void swap(int *a, int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

Array sort(Array arr){

    for(int i=0;i<arr.leng-1;i++){
        for(int j=0;j<arr.leng-i-1;j++){
            if(arr.ary[j]>arr.ary[j+1]){
                swap(&arr.ary[j],&arr.ary[j+1]);
            }
        }
    }
    return arr;
}

int main(){


    Array arr;
    cout<<"Enter size of the array: ";
    cin>>arr.size;

    cout<<"Enter number of elements: ";
    cin>>arr.leng;


    for(int i=0;i<arr.leng;i++){
        cout<<"ENter values: ";
        cin>>arr.ary[i];
    }

    disp(arr);

    Array sorted=sort(arr);

    disp(arr);






}