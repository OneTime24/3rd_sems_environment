

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool balanced(string exp){

    stack<int> stk;

    for(char ch : exp){

        
        if(ch=='(' || ch=='{' || ch=='['){
            stk.push(ch);
        }

        else if(ch==')' || ch=='}' || ch==']'){

            if(stk.empty()){
            return false;
        }
            char top=stk.top();
            stk.pop();

            if(ch==')' && top!='('){
                return false;
            }
            if(ch=='}' && top!='{'){
                return false;
            }
            if(ch==']' && top!='['){
                return false;
            }
        }
    }

    return stk.empty();
}


int main(){


    string str;

    getline(cin,str);

    if(balanced(str)){
        cout<<"STRING is balanced: \n";
    }else{
        cout<<"String is not balanced: \n";
    }


}