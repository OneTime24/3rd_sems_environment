///string reversal

#include <iostream>
using namespace std;


int main(){


    char name[]="Hello World!";


    int j=0;

    for(j=0;name[j]!='\0';j++){

    }
    j-=1;       //poinint to before null charac

    cout<<name<<endl;

    for(int i=0;i<j;i++,j--){

        int tmp=name[i];
        name[i]=name[j];
        name[j]=tmp;
    }

    cout<<name<<endl;





}