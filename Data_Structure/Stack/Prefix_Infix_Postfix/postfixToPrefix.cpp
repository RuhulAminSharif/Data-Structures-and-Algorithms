#include<bits/stdc++.h>
using namespace std;
bool isOperand( char ch ) {
    return (ch >= 'A' && ch <= 'Z') || ( ch >= 'a' && ch <= 'z' ) || ( ch >= '0' && ch <= '9' );
}
string postToPre(string postfix ) {
    stack<string> prefix;
    for( int i = 0; i < postfix.size(); i += 1 ) {
        string newTop = "";
        if( isOperand( postfix[i] ) ) {
            newTop += postfix[i];
        } else {
            string top1 = prefix.top();
            prefix.pop();
            string top2 = prefix.top();
            prefix.pop();
            newTop += postfix[i] + top2 + top1 ;
        }
        prefix.push( newTop );
    }
    return prefix.top();
}
int main()
{
    string postfix = "ABC/-AK/L-*";
    cout << postToPre(postfix) << endl;
    return 0;
}