#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9+7;
const ll mx = 1e7 + 5;
vector<ll> dp ( mx ) ;
void fib()
{
    dp[1] = 1;
    dp[2] = 1;
    for(ll i=3; i < mx; i += 1 ){
        dp[i] = ( dp[i-1] % mod + dp[i-2] % mod ) % mod;
    }
    return ;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fib();
    ll n; cin >> n;
    cout << dp[n] << endl;
    return 0;

}
