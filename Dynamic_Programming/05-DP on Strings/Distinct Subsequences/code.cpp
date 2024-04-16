// https://leetcode.com/problems/distinct-subsequences/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define inf 1e18
const ll mod = 1e9+7;
int numDistinct(string s, string t) {
    int mod=1e9+7;
    int n = s.size(), m = t.size();
    
    vector<vector<int>> dp ( n+1, vector<int> ( m+1 , 0 ) );
    
    for( int i = 0 ; i <= n ; i += 1 ) {
        dp[i][0] = 1;
    }
        
    for( int i=1; i <= n; i += 1 ) {
        for( int j=1; j <= m; j += 1 ) {
            if( s[i-1] == t[j-1] ) {
                dp[i][j] = ( dp[i-1][j] % mod + dp[i-1][j-1] % mod ) % mod ;
            }
            else {
                dp[i][j] = dp[i-1][j] % mod ;
            }
        }
    }
    return dp[n][m] % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
