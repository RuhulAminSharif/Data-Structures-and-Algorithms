#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mx = 1e6 + 5;
const ll mod = 1e9+7;
void mod_normal(ll &x) { x %= mod; if(x<0) x+=mod;}
ll mod_mul(ll x, ll y) { x %= mod; y %= mod; mod_normal(x); mod_normal(y); return (x*y)%mod; }
ll mod_add(ll x, ll y) { x %= mod; y %= mod; mod_normal(x); mod_normal(y); return (x+y)%mod; }
ll mod_sub(ll x, ll y) { x %= mod; y %= mod; mod_normal(x); mod_normal(y); x -= y; mod_normal(x); return x; }
ll mod_pow(ll b, ll p) { ll r = 1; while(p){ if(p&1) r = mod_mul(r, b); b = mod_mul(b, b); p >>= 1; } return r; }
ll modinverse(ll x){ return mod_pow(x,mod-2); } /// if mod is prime.
ll mod_div(ll x, ll y){ return mod_mul(x,modinverse(y)); }
vector<ll> fact(mx);
void initFact()
{
    fact[0] = 1;
    for( ll i = 1; i < mx; i += 1 ) {
        fact[i] = mod_mul( fact[i-1], i );
    }
    return ;
}
/// nCr
ll nCr( ll n, ll r )
{
    //ncr=n!/(r!*(n-r)!)
    ll numerator = fact[n];
    ll fact_r = fact[r];
    ll fact_nr = fact[n-r];
    ll denominator = mod_mul( fact_r, fact_nr );
    ll ncr = mod_mul( numerator, modinverse(denominator) );
    return ncr;
}
int main()
{
    initFact();
    ll t = 1; cin >> t;
    while( t-- ) {
        ll n, k; cin >> n >> k;
        cout <<  nCr(n,k) << endl;
    }
    return 0;
}
// https://cses.fi/problemset/task/1079