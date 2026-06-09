

#include <iostream>

using namespace std;

int n;          //global
int *retarr(){
    cout<<"Enter size of the array: ";
    cin>>n;

    int *arr=new int[n];

    return arr;
}

void inparr(int*pt){   
    for(int i=0;i<5;i++){
        cout<<"Enter "<<i+1<<" value: ";
        cin>>*(pt+i);
    }

}


struct testing{

    int tmp;
    int *arr=new int[tmp];
    
};

void modid(testing* ptr ){

    cout<<"Enter new size: ";
    int x;
    cin>>x;


    int *newarr=new int[x];


    for(int i=0;i<ptr->tmp;i++){
        newarr[i]=ptr->arr[i];
    }
    for(int i=ptr->tmp;i<x;i++){
        cout<<"Enter the new values to append at the end: ";
        cin>>newarr[i];
    }

    delete ptr->arr;
    ptr->tmp=x;
    ptr->arr=newarr;

}

int main(){

    // int n;
    // cout<<"enter size: ";
    // cin>>n;

    // int arr[n];

    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }


    // for(int x:arr){
    //     cout<<x<<endl;
    // }

    

    // int *ptr;
    
    // ptr= retarr();

    // inparr(ptr);

    // for(int i=0;i<n;i++){
    //     cout<<*(ptr+i)<<endl;
    // }




    testing r1;
    r1.tmp=5;

    for(int i=0;i<5;i++){
        cin>>r1.arr[i];
    }


    for(int i=0;i<5;i++){
        // cout<<"\nsize : "<<r1.n<<endl;
        cout<<r1.arr[i]<<endl;
    }  
    modid(&r1);

    for(int i=0;i<r1.tmp;i++){
        // cout<<"\nsize : "<<r1.n<<endl;
        cout<<r1.arr[i]<<endl;
    }  

    delete r1.arr;
}