#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string exp)
{
    stack<char> st;

    for(char ch : exp)
    {
        // Opening brackets
        if(ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }

        // Closing brackets
        else if(ch == ')' || ch == ']' || ch == '}')
        {
            if(st.empty())
                return false;

            char top = st.top();
            st.pop();

            if(ch == ')' && top != '(')
                return false;

            if(ch == ']' && top != '[')
                return false;

            if(ch == '}' && top != '{')
                return false;
        }
    }

    return st.empty();
}

int main()
{
    string exp;

    cout << "Enter expression: ";
    cin >> exp;

    if(isBalanced(exp))
        cout << "Balanced";
    else
        cout << "Not Balanced";
}