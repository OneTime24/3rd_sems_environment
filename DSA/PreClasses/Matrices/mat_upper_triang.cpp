#include <iostream>

using namespace std;

struct matrix{
    int *A;
    int n;
};

void setter(matrix m,int i, int j,int x){

    if(i<=j){
        // Fixed index formula for row-major upper triangular matrix
        m.A[(i-1)*m.n - ((i-2)*(i-1))/2 + (j-i)] = x;
    }
}

// Removed unnecessary parameter x
int getter(matrix m,int i, int j){

    if(i<=j){
        // Fixed index formula
        return m.A[(i-1)*m.n - ((i-2)*(i-1))/2 + (j-i)];
    }else{
        return 0;
    }
}

void create(matrix m){
    int x;
    cout<<"Enter all the elements:\n";

    // Fixed loop limits
    for(int i=1;i<=m.n;i++){
        for(int j=1;j<=m.n;j++){

            if(i<=j){
                cin>>x;
                setter(m,i,j,x);
            }
        }
    }
}

void display(matrix m){

    // Fixed loop limits
    for(int i=1;i<=m.n;i++){
        for(int j=1;j<=m.n;j++){

            if(i<=j){
                // Used getter() instead of repeating formula
                cout<<getter(m,i,j)<<" ";
            }else{
                cout<<"0 ";
            }
        }

        // Added newline after every row
        cout<<endl;
    }
}

int main(){

    matrix m;

    cout<<"Enter dimension of the array: ";
    cin>>m.n;

    // Fixed allocation size
    m.A = new int[m.n*(m.n+1)/2];

    create(m);
    display(m);

    // Added memory cleanup
    delete[] m.A;

    return 0;
}