//infix to postfix


#include <iostream>
#include <stack>
using namespace std;

int preced(char op)
{
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

bool isoperand(char ch){

    return !(ch == '+' || ch == '-' ||
             ch == '*' || ch == '/' ||
             ch == '^' || ch == '(' ||
             ch == ')');

}

string infixto(string exp){

    stack<char> st;
    string postfix="";

    for(char ch:exp){

        if(isoperand(ch)){
            postfix+=ch;
        }
        else if(ch=='('){
            st.push(ch);

        }
        else if (ch==')'){

            while(!st.empty() &&st.top()!='('){
                postfix+=st.top();
                st.pop();

            }

            if(!st.empty()){
                st.pop();
            }
        }else{
           while(!st.empty() &&
      (preced(st.top()) > preced(ch) ||
      (preced(st.top()) == preced(ch) && ch != '^'))){
                postfix+=st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
     while(!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;

}

int main(){

    string exp="(A+B)*C";
    cout<<infixto(exp);
    
}