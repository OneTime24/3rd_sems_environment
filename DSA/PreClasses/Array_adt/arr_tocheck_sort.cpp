

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


int main(){


    Array arr;
    cout<<"Enter size of the array: ";
    cin>>arr.size;

    arr.ary=new int[arr.size];
    cout<<"Enter number of elements: ";
    cin>>arr.leng;



    for(int i=0;i<arr.leng;i++){
        cout<<"ENter values: ";
        cin>>arr.ary[i];
    }

    disp(arr);

    Array sorted;
    sorted.size = arr.size;
    sorted.leng = arr.leng;
    sorted.ary = new int[arr.size];

    for(int i = 0; i < arr.leng; i++)
        sorted.ary[i] = arr.ary[i];

    sorted = sort(sorted);

    cout<<boolalpha<<check_sort(arr)<<endl;
    cout<<boolalpha<<check_sort(sorted)<<endl;




    disp(arr);

    neg_left(arr);

    disp(arr);
}