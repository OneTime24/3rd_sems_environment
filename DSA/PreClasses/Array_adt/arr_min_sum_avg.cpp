

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


int getA(Array arr, int ind){
    return arr.ary[ind];
}

void setA(Array arr,int ind,int val){

    arr.ary[ind]=val;
}

int getmx(Array arr){

    int mx=arr.ary[0];
    
    for(int i=0;i<arr.leng;i++){

        if(arr.ary[i]>mx){
            mx=arr.ary[i];
        }
    }
    return mx;
}

int getmn(Array arr){
    int mn=arr.ary[0];

    for(int i=0;i<arr.leng;i++){
        if(arr.ary[i]<mn){
            mn=arr.ary[i];
        }
    }

    return mn;
}

int sum(Array arr){
    int total;

    for(int i=0;i<arr.leng;i++){
        total+=arr.ary[i];
    }

    return total;
}

float avg(Array arr){

    int total;

    for(int i=0;i<arr.leng;i++){
        total+=arr.ary[i];
    }

    return total/arr.leng;
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

    // int x=search(arr);

    // if(x==-1){
    //     cout<<"Search Failed: ";

    // }else{
    //     cout<<"Value found at Index: "<<x<<endl;
    // }


    // cout<<endl<<getA(arr,4)<<endl;

    // setA(arr,4,10);
    // disp(arr);

    // cout<<endl<<getmx(arr)<<endl;



    cout<<"\nArray minimum: "<<getmn(arr)<<endl;

    cout<<"Arrat sum: "<<sum(arr)<<endl;

    cout<<"Average: "<<avg(arr)<<endl;
}