// starting again with focus



#include <iostream>

using namespace std;


struct matrix{

    int *mat;
    int n;
};

void seter(matrix m,int i, int j, int x){

    if(i==j){
        m.mat[i-1]=x;
    }
    
}

int geter(matrix m, int i, int j){
    if (i==j){
        return m.mat[i-1];
    }else{
        return 0;
    }
}

void display(matrix m){
    
for(int i=1;i<=m.n;i++){
    for(int j=1;j<=m.n;j++){
        if(i==j){
            cout<<m.mat[i-1]<<" ";
        }
        else{
            cout<<"0 ";
        }
    }
    cout<<"\n";
}
}
int main(){


    int sz;
    cout<<"Enter size: ";
    cin>>sz;
    matrix m;
    m.mat=new int[sz]();

    m.n=sz;

    seter(m,1,1,10);

    // cout<<geter(m,1,1);

    seter(m,2,2,20);

    seter(m,3,3,30);

    seter(m,4,4,40);


    display(m);


    delete m.mat;




}