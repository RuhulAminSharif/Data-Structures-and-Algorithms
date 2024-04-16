// https://cses.fi/problemset/result/8819992/
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
    ll n; cin >> n;
    vector<vector<char>> arr(n+5, vector<char>(n+5));
    for(ll i=1; i<=n; i++) {
        for(ll j=1; j<=n; j++) {
            cin >> arr[i][j];
        }
    }
    vector<vector<ll>> dp(n+5, vector<ll>(n+5, 0));
    if( arr[1][1] == '.' ) dp[1][1] = 1;
    for(ll i=1; i<=n; i++) {
        for(ll j=1; j<=n; j++) {
            if( i == 1 && j == 1 ) continue;
            else if( arr[i][j] == '.' ) dp[i][j] = ( dp[i][j-1] % mod + dp[i-1][j] % mod ) % mod;
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}