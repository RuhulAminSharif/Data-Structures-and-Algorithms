#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define inf 1e9
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, q; cin >> n >> q;
    vector<ll> v(n+1),pref(n+1,0);
    for( ll i = 1; i <= n; i += 1 ) cin >> v[i];
    for( ll i = 1; i <= n; i += 1 ) pref[i] += (pref[i-1]+v[i]);
    while( q-- ) {
        ll l, r; cin >> l >> r;
        cout << pref[r] - pref[l-1] << endl;
    }
    return 0;
}
// https://cses.fi/problemset/task/1646 