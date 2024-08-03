#include<bits/stdc++.h>
using namespace std;
bool isOperand( char ch ) {
    return (ch >= 'A' && ch <= 'Z') || ( ch >= 'a' && ch <= 'z' ) || ( ch >= '0' && ch <= '9' );
}
string preToPost(string prefix) {
    stack<string> postfix;
    for( int i = prefix.size()-1; i >= 0; i -= 1 ) {
        string newTop = "";
        if( isOperand( prefix[i] ) ) {
            newTop += prefix[i];
        }
        else {
            string top1 = postfix.top();
            postfix.pop();
            string top2 = postfix.top();
            postfix.pop();
            newTop += top1 + top2 + prefix[i];
        }
        postfix.push( newTop );
    }
    return postfix.top();
}
int main()
{
    string prefix = "*-A/BC-/AKL";
    cout << preToPost(prefix) << endl;
    return 0;
}