#include <bits/stdc++.h>
using namespace std;
bool isOperand(char ch) {
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return true;
    }
    return false;
}
int priority(char ch) {
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return -1;
}
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix;
    for (int i = 0; i < infix.size(); i += 1)
    {
        if (isOperand(infix[i]))
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(')
        {
            st.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() && priority(infix[i]) <= priority(st.top()))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
    }
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}
int main()
{
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout << infixToPostfix(infix) << endl;
    return 0;
}