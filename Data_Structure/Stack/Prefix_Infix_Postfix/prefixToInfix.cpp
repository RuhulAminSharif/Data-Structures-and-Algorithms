#include <bits/stdc++.h>
using namespace std;
bool isOperand(char ch)
{
  return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
}
string preToInfix(string prefix)
{
  stack<string> infix;
  for (int i = prefix.size() - 1; i >= 0; i -= 1) {
    string newTop = "";
    if (isOperand(prefix[i])) {
      newTop += prefix[i];
    }
    else {
      string top1 = infix.top();
      infix.pop();
      string top2 = infix.top();
      infix.pop();
      newTop += '(' + top1 + prefix[i] + top2 + ')';
    }
    infix.push(newTop);
  }
  return infix.top();
}
int main()
{
  return 0;
}