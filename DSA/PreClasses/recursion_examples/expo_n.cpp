

#include <iostream>
using namespace std;


int exp(int m,int n){

    if(n==0){
        return 1;
    }else{

        return exp(m,n-1)*m;
    }
}

//another version faster:

int fun(int m,int n){
    if(n==0){
        return 1;
    }

    if(n%2==0){
        return fun(m*m,n/2);
    }else{
        return m*fun(m*m,(n-1)/2);
    }
}

int main(){


    cout<<endl<<exp(4,3)<<endl;


    cout<<endl<<fun(4,3)<<endl;
}