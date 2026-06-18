

#include <iostream>
using namespace std;

int fun(int n){

    if(n==0){
        return 1;
    }else{
        return fun(n-1)*n;
    }
}


int fun1(int n){
    int tmp=1;

    for(int i=n;i>0;i--){
        tmp*=i;
    }

    return tmp;
}

int main(){


    // cout<<fun(4);

    cout<<fun1(4);

}


//using loops