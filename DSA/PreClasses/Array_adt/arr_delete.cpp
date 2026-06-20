

#include <iostream>
using namespace std;


struct Array{

    int *arry;
    int size;
    int length;
    
};


void inp(Array ar){

    cout<<"Enter values in the array: ";

    for(int i=0;i<ar.length;i++){
        cin>>ar.arry[i];
    }


}

void display(Array ar){
    cout<<"\nValues in the array: ";

    for(int i=0;i<ar.length;i++){
        cout<<ar.arry[i]<<" ";
    }
}

void del(Array *ar){
    cout<<"Enter Index to delete: ";
    int ind;
    cin>>ind;

    cout<<"Value at the given index is: "<<ar->arry[ind];


    for(int i=ind;i<ar->length-1;i++){

        ar->arry[i]=ar->arry[i+1];

    }
    ar->length--;
}

int main(){

    Array ar;

    cout<<"Enter array size: ";
    cin>>ar.size;

    ar.arry=new int[ar.size];
    cout<<"Enter number of elements: ";
    int n;
    cin>>n;
    ar.length=n;

    //to take input
    inp(ar);

    display(ar);

    del(&ar);

display(ar);


}