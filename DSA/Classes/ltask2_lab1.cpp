#include <iostream>
using namespace std;

void chk(char* a,int n,int ti){
    if(ti<0||ti>=n){
        cout<<"Invalid index";
        return;
    }

    char* p=a+ti;
    char c=*p;

    cout<<"Char: "<<c<<endl;

    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
       c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
        cout<<"Vowel"<<endl;
    else
        cout<<"Not Vowel"<<endl;

    cout<<"Address: "<<(void*)p<<endl;
}

int main(){
    char nm[]="MohsinAli";
    chk(nm,9,4);
    return 0;
}