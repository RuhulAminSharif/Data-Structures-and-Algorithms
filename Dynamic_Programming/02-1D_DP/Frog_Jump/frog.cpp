// https://atcoder.jp/contests/dp/tasks/dp_a
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define inf 1e18
const int N = 1e5;
ll a[N+5], memo[N+5];
ll recursiveSolution(ll n)
{
    if( n == 1 ) return 0;
    else if ( n == 2 ) return abs(a[n]-a[n-1]);
    ll one = recursiveSolution(n-1) + abs(a[n-1]-a[n]);
    ll two = recursiveSolution(n-2) + abs(a[n-2]-a[n]);
    return min(one, two);
}
ll memoizationSolution(ll n)
{
    if( n == 1 ) return 0;
    else if ( n == 2 ) return abs(a[n]-a[n-1]);
    else if( memo[n] != -1 ) return memo[n];
    ll one = memoizationSolution(n-1) + abs(a[n-1]-a[n]);
    ll two = memoizationSolution(n-2) + abs(a[n-2]-a[n]);
    memo[n] = min(one, two);
    return memo[n];
}
ll tabulationSolution(ll n)
{
    ll dp[n+1] = {0};
    dp[1] = 0;
    dp[2] = abs(a[2]-a[1]);
    for(ll i=3; i<=n; i++){
        ll one = dp[i-1] + abs(a[i]-a[i-1]);
        ll two = dp[i-2] + abs(a[i]-a[i-2]);
        dp[i] = min(one, two);
    }
    return dp[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n; cin >> n;
    for(ll i=1; i<=n; i++){
        cin >> a[i];
        memo[i] = -1;
    }
    /// cout << recursiveSolution(n) << endl;
    /// cout << memoizationSolution(n) << endl;
    cout << tabulationSolution(n) << endl;
    return 0;
}
