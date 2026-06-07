

#include <iostream>

using namespace std;

int main(){

    int n;
    cout<<"enter size: ";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


    for(int x:arr){
        cout<<x<<endl;
    }
}