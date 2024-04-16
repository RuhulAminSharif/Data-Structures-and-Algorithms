// https://atcoder.jp/contests/dp/tasks/dp_b
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define inf 1e18
const int N = 1e5;
ll a[N+5], memo[N+5];
ll recursiveSolution(ll n, ll k)
{
    if( n == 1 ) return 0;
    else if ( n == 2 ) return abs(a[n]-a[n-1]);

    ll req = inf;
    for(ll i=1; i<=k; i++){
        if( (n-i) >= 1 ) {
            ll take = recursiveSolution(n-i, k) + abs(a[n-i]-a[n]);
            req = min(req, take);
        }
    }

    return req;
}
ll memoizationSolution(ll n, ll k)
{
    if( n == 1 ) return 0;
    else if ( n == 2 ) return abs(a[n]-a[n-1]);
    else if( memo[n] != -1 ) return memo[n];
    ll req = inf;
    for(ll i=1; i<=k; i++){
        if( (n-i) >= 1 ) {
            ll take = memoizationSolution(n-i, k) + abs(a[n-i]-a[n]);
            req = min(req, take);
        }
    }
    memo[n] = req;
    return memo[n];
}
ll tabulationSolution(ll n, ll k)
{
    ll dp[n+1] = {0};
    dp[1] = 0;
    dp[2] = abs(a[2]-a[1]);
    for(ll i=3; i<=n; i++){
        ll req = inf;
        for(ll j=1; j<=k; j++){
            if( (i-j) >= 1 ){
                ll take = dp[(i-j)] + abs(a[i]-a[i-j]);
                req = min(req,take);
            }
        }
        dp[i] = req;
    }
    return dp[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, k; cin >> n >> k;
    for(ll i=1; i<=n; i++){
        cin >> a[i];
        memo[i] = -1;
    }
    /// cout << recursiveSolution(n, k) << endl;
    /// cout << memoizationSolution(n, k) << endl;
    cout << tabulationSolution(n, k) << endl;
    return 0;
}
