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


bool isdigit(char ch){
    return ch >= '0' && ch <= '9';
}

int evaluate(string exp){

    stack <int> sta;
    
    for(char ch:exp){

        if(isdigit(ch)){
            sta.push(ch-'0');
        }else{
            int b=sta.top();
            sta.pop();
            int a=sta.top();
            sta.pop();


            switch(ch){
                 case '+':
                    sta.push(a + b);
                    break;

                case '-':
                    sta.push(a - b);
                    break;

                case '*':
                    sta.push(a * b);
                    break;

                case '/':
                    sta.push(a / b);
                    break;
            }
        }

    }
    return sta.top();
}
int main(){

string postfix = infixto("(1+2)*3");
cout << postfix << endl;
cout << evaluate(postfix);
    
}