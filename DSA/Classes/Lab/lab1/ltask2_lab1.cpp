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
    // char *nm;
    // // nm=new char[100];                 //does work but ISO c++ forbids string constant to char* so we using direct char nm[] for this one only
    // nm="MohsinAli";
    chk(nm,9,0);
    return 0;
}