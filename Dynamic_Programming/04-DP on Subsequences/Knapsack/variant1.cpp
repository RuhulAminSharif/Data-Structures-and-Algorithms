/*
Problem Statement: https://atcoder.jp/contests/dp/tasks/dp_d
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define inf 1e18
ll recursiveSolution( ll n, ll weight, vector<pair<ll,ll>>& items )
{
    if( n == 0 ) {
        ll value = 0;
        if( weight >= items[0].first ) {
            value = items[0].second;
        }
        return value;
    }
    ll take = 0, not_take = 0 ;
    ll curr_w = items[n].first;
    ll value = items[n].second;
    not_take = recursiveSolution( n-1, weight, items );
    if( weight >= curr_w ) {
        take = value + recursiveSolution( n-1, weight - curr_w, items );
    }
    return max( take, not_take );
}
ll memoization( ll n, ll weight, vector<pair<ll,ll>>& items, vector<vector<ll>>& memo)
{
    if( n == 0 ) {
        ll value = 0;
        if( weight >= items[0].first ) {
            value = items[0].second;
        }
        return value;
    }
    else if ( memo[n][weight] != -1 ) return memo[n][weight];
    ll take = 0, not_take = 0 ;
    ll curr_w = items[n].first;
    ll value = items[n].second;
    if( weight >= curr_w ) {
        take = value + memoization( n-1, weight - curr_w, items, memo );
    }
    not_take = memoization( n-1, weight, items, memo );
    memo[n][weight] = max( take, not_take );
    return memo[n][weight];
}
ll tabultaion( ll n, ll w, vector<pair<ll,ll>> items )
{
    vector<vector<ll>>dp(n, vector<ll> ( w+1, 0 )) ;
    // for first bag i.e., idx = 0
    dp[0][0] = 0;
    ll w_0 = items[0].first;
    ll v_0 = items[0].second;
    for(ll j = 1; j<w_0 && j<=w ; j++) {
        dp[0][j] = 0;
    }
    for( ll j = w_0; j <= w; j++) {
        dp[0][j] = v_0;
    }

    // iterate till end

    for(ll bag=1; bag<n; bag++ ) {
        for(ll weight=1; weight<=w; weight++){
            ll curr_w = items[bag].first;
            ll value = items[bag].second;
            ll not_take = dp[bag-1][weight];
            ll take = 0;
            if( weight >= curr_w ) {
                take = value + dp[bag-1][weight-curr_w];
            }
            dp[bag][weight] = max( take, not_take );
        }
    }
    return dp[n-1][w];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, w; cin >> n >> w;
    vector<pair<ll,ll>> items ( n ) ;
    for(ll i=0; i<n; i++) {
        cin >> items[i].first >> items[i].second;
    }

    /// cout << recursiveSolution( n-1, w, items ) << endl;

    /// vector<vector<ll>> memo ( n, vector<ll> ( w + 1, -1) ) ;
    /// cout << memoization( n-1, w, items, memo ) << endl;

    cout << tabultaion( n, w, items) << endl;
    return 0;
}
