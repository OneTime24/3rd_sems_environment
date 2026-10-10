#include <iostream>
#include <string>
using namespace std;

class charstack{

    private:

    char arr[100];
    int top;

    public:

    charstack(){
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

class intstack{

    private:

    int arr[100];
    int top;

    public:

    intstack(){
        top=-1;
    }

    bool isEmpty(){
        return top==-1;
    }

    void push(int val){
        top++;
        arr[top]=val;
    }

    int pop(){
        int val=arr[top];
        top--;
        return val;
    }
};

int precedence(char op){

    if(op=='+' || op=='-')
        return 1;
    if(op=='*' || op=='/')
        return 2;
    return 0;
}

bool isOperator(char c){
    return c=='+' || c=='-' || c=='*' || c=='/';
}

string infixToPostfix(string infix){

    charstack st;
    string postfix="";

    for(int i=0;i<infix.length();i++){

        char c=infix[i];

        if(c==' ')
            continue;

        if(isdigit(c)){
            postfix+=c;
        }
        else if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(!st.isEmpty() && st.peek()!='('){
                postfix+=st.pop();
            }
            st.pop(); // remove the '('
        }
        else if(isOperator(c)){

            while(!st.isEmpty() && st.peek()!='(' && precedence(st.peek())>=precedence(c)){
                postfix+=st.pop();
            }
            st.push(c);
        }
    }

    while(!st.isEmpty()){
        postfix+=st.pop();
    }

    return postfix;
}

int evalPostfix(string postfix){

    intstack st;

    for(int i=0;i<postfix.length();i++){

        char c=postfix[i];

        if(isdigit(c)){
            st.push(c-'0'); // for single digit calc only
        }
        else if(isOperator(c)){

            int b=st.pop();
            int a=st.pop();
            int res=0;

            if(c=='+')
                res=a+b;
            else if(c=='-')
                res=a-b;
            else if(c=='*')
                res=a*b;
            else if(c=='/')
                res=a/b;

            st.push(res);
        }
    }

    return st.pop();
}

int main(){

    string infix;
    cout<<"enter infix expression: ";
    cin>>infix;

    string postfix=infixToPostfix(infix);
    cout<<"postfix: "<<postfix<<endl;

    int result=evalPostfix(postfix);
    cout<<"result: "<<result<<endl;

}