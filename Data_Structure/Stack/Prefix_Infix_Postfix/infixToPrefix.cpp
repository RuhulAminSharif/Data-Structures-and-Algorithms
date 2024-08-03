#include <bits/stdc++.h>
using namespace std;
bool isOperand(char ch)
{
  return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
}
int priority(char ch)
{
  if (ch == '^')
    return 3;
  if (ch == '*' || ch == '/')
    return 2;
  if (ch == '+' || ch == '-')
    return 1;
  return -1;
}
string infixToPrefix(string infix)
{
  reverse(infix.begin(), infix.end());
  for (int i = 0; i < infix.size(); i++)
  {
    if (infix[i] == '(')
      infix[i] = ')';
    else if (infix[i] == ')')
      infix[i] = '(';
  }

  string postfix = "";
  stack<char> st;
  for (int i = 0; i < infix.size(); i += 1)
  {
    if (isOperand(infix[i]))
      postfix += infix[i];
    else if (infix[i] == '(')
      st.push(infix[i]);
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
    else if (infix[i] == '^')
    {
      while (!st.empty() && priority(infix[i]) <= priority(st.top()))
      {
        postfix += st.top();
        st.pop();
      }
      st.push(infix[i]);
    }
    else
    {
      while (!st.empty() && priority(infix[i]) < priority(st.top()))
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
  string prefix = postfix;
  reverse(prefix.begin(), prefix.end());
  return prefix;
}
int main()
{
  string infix = "x+y*z/w+u";
  cout << infixToPrefix(infix) << endl;
  return 0;
}