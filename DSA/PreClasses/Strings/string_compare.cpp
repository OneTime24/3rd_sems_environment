

#include <iostream>
using namespace std;


int main(){

    char str1[]="Hello World";

    char str2[]="Hello World";

    int ln;
    int tmp;

    for(int i=0,j=0; str1[i]!='\0' && str2[j]!='\0';i++,j++){
        ln=i;
        if(str1[i]!=str2[j]){
            break;

        }
        else if(str1[i]==str2[j]){
            tmp=i;
        }
    }


    if(tmp==ln){
        cout<<"EQUAL";
    }else{ 
        cout<<"NOT EQUAL";
    }
}