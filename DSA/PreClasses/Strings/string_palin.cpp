
#include <iostream>
using namespace std;


int main(){

    char str1[]="ADAM";

    int i=0;
    int cnt=0;

    for(i=0;str1[i]!='\0';i++){
    }
    i-=1;

    for(int j=0;j<i;j++,i--){
        if(str1[j]==str1[i]){
            cnt++;
        }
    }

    if(cnt==i){
        cout<<"PALINDROME: ";
    }else{
        cout<<"NOT PALINDORME: ";
    }




}