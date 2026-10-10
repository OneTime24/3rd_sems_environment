#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class stack{

    private:

    char arr[1000];
    int top;

    public:

    stack(){
        top=-1;
    }

    bool isEmpty(){
        return top==-1;
    }

    void push(char val){
        top++;
        arr[top]=val;
    }

    char pop(){
        char val=arr[top];
        top--;
        return val;
    }
};

int main(){

    string s;
    cout<<"enter the string: ";
    getline(cin,s);

    stack st;
    string clean="";

    // ignore spaces and case, only pushing actual letters/digits
    for(int i=0;i<s.length();i++){
        char c=s[i];

        if(c==' ')
            continue;

        c=tolower(c);
        clean+=c;
        st.push(c);
    }

    string rev="";
    while(!st.isEmpty()){
        rev+=st.pop();
    }

    if(clean==rev){
        cout<<"Palindrome\n";
    }else{
        cout<<"Not Palindrome\n";
    }

}