

#include <iostream>
#include <stack>
using namespace std;

bool check_p(string exp){

    stack<char> st;

    for(char ch:exp){

        if(ch=='('){
            st.push(ch);
        }else if(ch==')'){

            if(st.empty()){
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main(){

    cout<<check_p("((a+b))");
}