#include <iostream>

using namespace std;

struct matrix{
    int *mat;
    int n;
};

void seter(matrix m,int i,int j,int x){
    if(i>=j){
        m.mat[i*(i-1)/2+j-1]=x;
    }
}

int geter(matrix m,int i,int j){
    if(i>=j){
        return m.mat[i*(i-1)/2+j-1];
    }
    return 0;
}

void display(matrix m){
    for(int i=1;i<=m.n;i++){
        for(int j=1;j<=m.n;j++){
            if(i>=j){
                cout<<m.mat[i*(i-1)/2+j-1]<<" ";
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

    m.mat = new int[sz*(sz+1)/2]();   // FIXED: Allocate n(n+1)/2 elements for lower triangular matrix
    m.n = sz;

    int x;
    cout<<"Enter all the elements: ";

    for(int i=1;i<=sz;i++){           // FIXED: Changed to 1-based indexing
        for(int j=1;j<=sz;j++){       // FIXED: Changed to 1-based indexing
            cin>>x;
            seter(m,i,j,x);
        }
    }

    display(m);

    delete[] m.mat;                   // FIXED: Use delete[] for arrays

    return 0;
}