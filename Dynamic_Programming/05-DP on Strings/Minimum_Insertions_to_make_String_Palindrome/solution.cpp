// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/submissions/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define inf 1e18
const ll mod = 1e9+7;
int minInsertions(string s) {
    int len = s.size();
    string t = s;
    reverse( t.begin(), t.end() ) ;
    vector<vector<int>> dp ( len+1, vector<int> ( len + 1 , 0 ) ) ;
    for( int i = 1; i <= len; i += 1 ) {
        for( int j = 1; j <= len; j += 1 ) {
            if( s[i-1] == t[j-1] ) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return len - dp[len][len];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}
