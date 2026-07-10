



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

bool check_sort(Array arr){

    for(int i=0;i<arr.leng-1;i++){
        if(arr.ary[i]>arr.ary[i+1]){
            return false;
        }
    }
    return true;
}

void neg_left(Array arr){

    int i=0;
    int j=arr.leng-1;

    while(i<j){

        while(arr.ary[i]<0){
            i++;
        }
        while(arr.ary[j]>=0){
            j--;
        }

        if(i<j){
            swap(&arr.ary[i],&arr.ary[j]);
        }
    }
}

Array merge(Array arr1,Array arr2){

    int i=0,j=0,k=0;

    Array tmp;
    tmp.size = arr1.size + arr2.size;
    tmp.leng = arr1.leng + arr2.leng;
    tmp.ary = new int[tmp.size];
    while(i<arr1.leng && j<arr2.leng){

        if(arr1.ary[i]<arr2.ary[j]){
            tmp.ary[k++]=arr1.ary[i++];
        }else{
            tmp.ary[k++]=arr2.ary[j++];
        }
    }

        for(;i<arr1.leng;i++){
            tmp.ary[k++]=arr1.ary[i];
        }

        for(;j<arr2.leng;j++){
            tmp.ary[k++]=arr2.ary[j];
        }

    

    return tmp;
}


int main(){


    Array arr;
    cout<<"Enter size of the array: ";
    cin>>arr.size;

    arr.ary=new int[arr.size];
    cout<<"Enter number of elements: ";
    cin>>arr.leng;



    for(int i=0;i<arr.leng;i++){
        cout<<"ENter values of array 1: ";
        cin>>arr.ary[i];
    }


    Array arr2;
    cout<<"Enter size of the array: ";
    cin>>arr2.size;

    arr2.ary=new int[arr2.size];
    cout<<"Enter number of elements: ";
    cin>>arr2.leng;



    for(int i=0;i<arr2.leng;i++){
        cout<<"ENter values of array 2: ";
        cin>>arr2.ary[i];
    }

    sort(arr);
    sort(arr2);
    Array arr3=merge(arr,arr2);

    disp(arr3);


}