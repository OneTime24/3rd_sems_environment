


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

void swap(int *a, int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

float avg(Array arr){

    int total;

    for(int i=0;i<arr.leng;i++){
        total+=arr.ary[i];
    }

    return total/arr.leng;
}


void  revs(Array &arr){

    for(int i=0,j=arr.leng-1;i<j;i++,j--){
        swap(arr.ary[i],arr.ary[j]);
    }


}

Array left_shift(Array arr){
    cout<<"How many left shift: ";
    int n;
    cin>>n; 
    int x=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<arr.leng-1;j++){
            arr.ary[j]=arr.ary[j+1];
        }
        arr.ary[arr.leng-1]=0;
    }

    return arr;
}

Array left_rotate(Array arr){
    cout<<"How many left shift: ";
    int n;
    cin>>n; 
    int x=0;
    for(int i=0;i<n;i++){

        int tmp=arr.ary[0];
        for(int j=0;j<arr.leng-1;j++){
            arr.ary[j]=arr.ary[j+1];
        }
        arr.ary[arr.leng-1]=tmp;
    }

    return arr;
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



    // cout<<"\nArray minimum: "<<getmn(arr)<<endl;

    // cout<<"Arrat sum: "<<sum(arr)<<endl;

    // cout<<"Average: "<<avg(arr)<<endl;

    // revs(arr);

    // disp(arr);

    Array ptr=left_shift(arr);
    disp(ptr);

    Array pt2=left_rotate(arr);
    disp(pt2);

    
}