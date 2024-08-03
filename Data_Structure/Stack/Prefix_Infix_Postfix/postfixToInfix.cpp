#include <bits/stdc++.h>
using namespace std;
bool isOperand(char ch) {
  return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
}
string postToInfix(string postfix) {
  stack<string> infix;
  for (int i = 0; i < postfix.size(); i += 1) {
    string newTop = "";
    if (isOperand(postfix[i])) {
      newTop = postfix[i];
    }
    else {
      string top1 = infix.top();
      infix.pop();
      string top2 = infix.top();
      infix.pop();
      newTop = '(' + top2 + postfix[i] + top1 + ')';
    }
    infix.push(newTop);
  }
  return infix.top();
}
int main()
{
  string postfix = "ab*c+";
  cout << postToInfix(postfix) << endl;
  return 0;
}