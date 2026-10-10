#include <iostream>
#include <string>
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

    char peek(){
        return arr[top];
    }
};

bool isMatch(char open,char close){

    if(open=='(' && close==')')
        return true;
    if(open=='[' && close==']')
        return true;
    if(open=='{' && close=='}')
        return true;
    return false;
}

int main(){

    string s;
    cout<<"enter the line: ";
    getline(cin,s);

    stack st;
    bool balanced=true;
    int badindex=-1;

    for(int i=0;i<s.length();i++){

        char c=s[i];

        if(c=='(' || c=='[' || c=='{'){
            st.push(c);
        }
        else if(c==')' || c==']' || c=='}'){

            if(st.isEmpty()){
                balanced=false;
                badindex=i;
                break;
            }

            char top=st.pop();

            if(!isMatch(top,c)){
                balanced=false;
                badindex=i;
                break;
            }
        }
    }

    if(balanced && !st.isEmpty()){
        // leftover opening brackets never got closed
        balanced=false;
        badindex=s.length();
    }

    if(balanced){
        cout<<"Balanced\n";
    }else{
        cout<<"Not Balanced\n";
        cout<<"first offending index: "<<badindex<<endl;
    }

}