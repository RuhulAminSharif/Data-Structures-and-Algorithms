// https://leetcode.com/problems/edit-distance/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define inf 1e18
const ll mod = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s, t; cin >> s >> t;
    ll n = s.size(), m = t.size();
    ll dp[n+5][m+5] ={ 0 };
    for(ll i=0; i<=m; i++) dp[0][i] = i;
    for(ll i=0; i<=n; i++) dp[i][0] = i;
    for(ll i=1; i<=n; i++) {
        for(ll j = 1; j<=m; j++) {
            if( s[i-1] == t[j-1] ) {
                dp[i][j] = dp[i-1][j-1];
            } else{
                // (i-1, j-1) - replace
                // (i, j-1) - insert
                // (i-1, j) - delete
                dp[i][j] = 1 + min( dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}