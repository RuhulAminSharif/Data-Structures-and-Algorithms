#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const ll mod = 1e9+7;
void mod_normal(ll &x) { x %= mod; if(x<0) x+=mod;}
ll mod_mul(ll x, ll y) { x %= mod; y %= mod; mod_normal(x); mod_normal(y); return (x*y)%mod; }
ll mod_add(ll x, ll y) { x %= mod; y %= mod; mod_normal(x); mod_normal(y); return (x+y)%mod; }
ll mod_sub(ll x, ll y) { x %= mod; y %= mod; mod_normal(x); mod_normal(y); x -= y; mod_normal(x); return x; }
ll mod_pow(ll b, ll p) { ll r = 1; while(p){ if(p&1) r = mod_mul(r, b); b = mod_mul(b, b); p >>= 1; } return r; }
ll modinverse(ll x){ return mod_pow(x,mod-2); } /// if mod is prime.
ll mod_div(ll x, ll y){ return mod_mul(x,modinverse(y)); }
vector<vector<ll>> matrixMultiply( vector<vector<ll>>&a, vector<vector<ll>>&b )
{
    ll row = a.size();
    ll col = b[0].size();
    ll shared = a[0].size(); // b.size()
    vector<vector<ll>> prod(row,vector<ll>(col,0));
    for( ll i = 0; i < row; i += 1 ) {
        for( ll j = 0; j < col; j += 1 ) {
            ll sum = 0;
            for( ll k = 0; k < shared; k += 1 ) {
                /// sum += (a[i][k] * b[k][j]);
                sum = mod_add( sum, mod_mul( a[i][k], b[k][j] ));
            }
            prod[i][j] = sum;
        }
    }
    return prod;
}
vector<vector<ll>> matrixExponentiation( vector<vector<ll>>&mat, ll n )
{
    ll m = mat.size();
    vector<vector<ll>>res(m, vector<ll>(m,0));
    for( ll i = 0;  i < m; i += 1 ) {
        for( ll j = 0; j < m; j += 1 ) {
            if( i == j ) res[i][j] = 1;
        }
    }
    while( n ) {
        if( n & 1 ) {
            res = matrixMultiply(res,mat);
        }
        mat = matrixMultiply(mat,mat);
        n >>= 1;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1; cin >> t;
    while( t-- ) {
        ll m, n; cin >> m >> n;
        vector<vector<ll>>mat(m, vector<ll>(m));
        for( ll i = 0; i < m; i += 1 ) {
            for( ll j = 0; j < m; j += 1 ) {
                cin >> mat[i][j];
            }
        }
        vector<vector<ll>> ans = matrixExponentiation(mat,n);
        for( ll i = 0; i < m; i += 1 ) {
            for( ll j = 0; j < m; j += 1 ) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

// https://www.spoj.com/problems/MPOW/ 