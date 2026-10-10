
#include <iostream>
#include <stack>
using namespace std;

bool isoperand(char ch) {
    return !(ch == '+' || ch == '-' || ch == '*' ||
             ch == '/' || ch == '^' || ch == '(' || ch == ')');
}

int precedence(char ch) {
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

string to_post(string exp) {
    stack<char> stk;
    string post = "";

    for (char ch : exp) {
        if (ch == ' ')
            continue;

        if (isoperand(ch)) {
            post += ch;
        }
        else if (ch == '(') {
            stk.push(ch);
        }
        else if (ch == ')') {
            while (!stk.empty() && stk.top() != '(') {
                post += stk.top();
                stk.pop();
            }
            if (!stk.empty())
                stk.pop();
        }
        else {
            while (!stk.empty() && stk.top() != '(' &&
                   (precedence(stk.top()) > precedence(ch) ||
                   (precedence(stk.top()) == precedence(ch) && ch != '^'))) {
                post += stk.top();
                stk.pop();
            }
            stk.push(ch);
        }
    }

    while (!stk.empty()) {
        post += stk.top();
        stk.pop();
    }

    return post;
}

int main() {
    string exp;
    cin >> exp;

    cout << to_post(exp);
}
