#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
bool kuhn( ll u, vector<vector<ll>>&adj, vector<ll>& left, vector<ll>& right, vector<bool>& vis )
{
    for( auto v : adj[u] ) {
        if( !vis[v] ) {
            vis[v] = true;
            if( right[v] == -1 || kuhn( right[v], adj, left, right, vis ) ) {
                right[v] = u;
                left[u] = v;
                return true;
            }
        }
    }
    return false;
}
ll bipartiteMatching( ll n, ll m, vector<vector<ll>>& adj )
{
    vector<ll> left( n + 1, -1 );
    vector<ll> right( m + 1, -1 );
    ll cnt = 0;
    for( ll i = 1; i <= n; i += 1 ) {
        vector<bool> vis( m + 1, false );
        if( kuhn( i , adj, left, right, vis ) ) {
            cnt += 1;
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1; cin >> t;
    for( ll test = 1; test <= t; test += 1 ) {
        cout << "Case " << test << ": ";
        ll n; cin >> n;
        vector<ll> captains( n + 1 );
        for( ll i = 1; i <= n; i += 1 ) cin >> captains[i];
        ll m; cin >> m;
        vector<ll> teams( m + 1 );
        for( ll i = 1; i <= m; i += 1 ) cin >> teams[i];

        vector<vector<ll>> adj( n + 1 );
        for (ll i = 1; i <= n; i += 1) {
            for (ll j = 1; j <= m; j += 1) {
                if (teams[j] % captains[i] == 0) {
                    adj[i].push_back(j);
                }
            }
        }
        cout << bipartiteMatching( n, m, adj ) << endl;
    }
    return 0;
}
// https://vjudge.net/contest/708756#problem/C