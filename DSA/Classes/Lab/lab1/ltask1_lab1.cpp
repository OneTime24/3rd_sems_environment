

#include <iostream>

using namespace std;


void analyzeArray(int* arr, int size) {
int* p = arr;
int total = 0;
for (int i = 0; i<size; i++) {
    total += *p;
    p++; 
}
int average = total / size;
int* maxPtr = arr;
p = arr; 
for (int i = 0;i<size; i++) {
if (*p>*maxPtr) {
    maxPtr = p;
}
p++;
}


cout<<"Total: "<<total<<endl;
cout<<"Average: "<<average<<endl;

cout<<"MAXIMUM NUmber: "<<*(maxPtr)<<" Addresss: "<<maxPtr<<endl;

}


int main(){

    int *arr=new int[7];

    *(arr+0)=9000;
    *(arr+1)=12000;
    *(arr+2)=10000;
    *(arr+3)=15000;
    *(arr+4)=12000;
    *(arr+5)=13000;
    *(arr+6)=6000;


    analyzeArray(arr,7);


}