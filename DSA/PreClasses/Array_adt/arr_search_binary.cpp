

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



int binsearch(Array arr){

    int key;
    cout<<"\nEnter Value to serach for: \n";
    cin>>key;
    int l=0;
    int h=arr.leng-1;
    int mid;

    while(l<=h){

    mid=(l+h)/2;
        if(key==arr.ary[mid]){
            return mid;
        }else if(key<arr.ary[mid]){
            h=mid-1;
        }else{
            l=mid+1;
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


    int x=binsearch(arr);


    cout<<"Value found at index: "<<x;
    disp(arr);
}