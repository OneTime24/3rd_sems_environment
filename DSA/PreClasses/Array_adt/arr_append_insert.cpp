

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

void append(Array *ar,int x){

    ar->arry[ar->length]=x;
    ar->length++;

}

void insert(Array *ar,int ind,int val){

    if(ind>=0 && ind<=ar->length){

        for(int i=ar->length;i>ind;i--){

            ar->arry[i]=ar->arry[i-1];

        }

        ar->arry[ind]=val;
        ar->length++;
    }
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

    append(&ar,10);
    
    display(ar);

    insert(&ar,4,15);

    display(ar);


}