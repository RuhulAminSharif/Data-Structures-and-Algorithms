// https://leetcode.com/problems/wildcard-matching/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define inf 1e18
const ll mod = 1e9+7;
bool isMatch(string s, string p) {
    // p contains ?, *, lowercase
    // s contains text of lowercase letters
    int n = p.size(), m = s.size();
    vector<vector<bool>> dp ( n + 1 , vector<bool> ( m + 1 , false ) ) ;
        
    dp[0][0] = true;
    
    for( int i = 1; i <= n; i += 1 ) {
        bool fg = true;
        for( int idx = 0; idx < i; idx += 1 ) {
            if( p[idx] != '*' ) {
                fg = false;
                break;
            }
        }
        dp[i][0] = fg;
    }
    for( int i = 1; i <= n; i += 1 ) {
        for( int j = 1; j <= m; j += 1 ) {
            if( p[i-1] == s[j-1] || p[i-1] == '?' ) {
                dp[i][j] = dp[i-1][j-1];
            } else if ( p[i-1] == '*' ) {
                dp[i][j] = dp[i-1][j] || dp[i][j-1] ;
            } else {
                dp[i][j] = false;
            }
        }
    }
    return dp[n][m];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
