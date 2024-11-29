#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mx = 1e8;
vector<ll>prime;
void sieve()
{
    vector<bool>vis(mx+1,true);
    vis[0]=vis[1] = false;
    for( ll i = 3; i * i <= mx; i += 2 ) {
        if( vis[i] ) {
            for( ll j = i * i; j <= mx; j += 2 * i ) {
                vis[j] = false;
            }
        }
    }
    prime.push_back(2);
    for(ll i = 3; i <= mx; i += 2){
        if( vis[i] ){
            prime.push_back(i);
        }
    }
}
vector<pair<ll,ll>> get_occurance( ll n )
{
    vector<pair<ll,ll>>occurance;
    for( ll i = 0; prime[i] * prime[i] <= n ; i += 1 ) {
        if( n % prime[i] == 0 ) {
            ll cnt = 0 ;
            while( n % prime[i] == 0 ){
                n /= prime[i];
                cnt += 1;
            }
            if( cnt ) occurance.push_back({prime[i],cnt});
        }
    }
    if( n > 1 ) occurance.push_back({n,1});
    return occurance;
}
ll get_nod( ll n )
{
    vector<pair<ll,ll>> occurance = get_occurance(n);
    ll nod = 1, len = occurance.size();
    for( ll i = 0; i < len; i += 1 ) {
        nod *= ( occurance[i].second + 1 );
    }
    return nod;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    sieve();
    ll t; cin >> t;
    while( t-- ) {
        ll n; cin >> n;
        cout << get_nod(n) << endl;
    }
    return 0;
}

// https://cses.fi/problemset/task/1713