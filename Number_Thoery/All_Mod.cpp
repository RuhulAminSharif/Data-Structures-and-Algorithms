#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9+7;
void mod_normal(ll &x) { x %= mod; if(x<0) x+=mod;}
ll mod_mul(ll x, ll y) { x %= mod; y %= mod; mod_normal(x); mod_normal(y); return (x*y)%mod; }
ll mod_add(ll x, ll y) { x %= mod; y %= mod; mod_normal(x); mod_normal(y); return (x+y)%mod; }
ll mod_sub(ll x, ll y) { x %= mod; y %= mod; mod_normal(x); mod_normal(y); x -= y; mod_normal(x); return x; }
ll mod_pow(ll b, ll p) { ll r = 1; while(p){ if(p&1) r = mod_mul(r, b); b = mod_mul(b, b); p >>= 1; } return r; }
ll modinverse(ll x){ return mod_pow(x,mod-2); } /// if mod is prime.
ll mod_div(ll x, ll y){ return mod_mul(x,modinverse(y)); }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}