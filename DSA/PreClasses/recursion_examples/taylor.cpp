

//taylor series:


#include <iostream>
using namespace std;


double e(int x, int n){

    static double s;

    if(n==0){
        return s;
    }else{

        s=1+x*s/n;

        return e(x,n-1);
    }
}


//using loops


double ex(int x,int n){
     double s=1;
     double nm=1;
     double dm=1;

    
    for(int i=0;i<=n;i++){
        nm*=x;
        dm*=i;
        s+=nm/dm;

    }

    return s;
}
int main(){


    cout<<"\nTaylor series recursion: "<<e(2,10);

    cout<<"\nTaylor series loops: "<<e(2,10);

}
