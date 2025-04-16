#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
bool isBipartite( ll V, vector<vector<ll>>& adj ) // 1 - based
{
    vector<ll> color(V + 1, -1);
    for (int i = 1; i <= V; i += 1) {
        if( color[i] == -1) {
            queue<ll> q;
            q.push(i);
            color[i] = 0;
            while( q.size() > 0 ) {
                ll u = q.front();
                q.pop();
                for( auto v : adj[u]) {
                    if( color[v] == -1) {
                        color[v] = !color[u];
                        q.push(v);
                    }
                    else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll V;
    while( cin >> V && V ) {
        ll E; cin >> E;
        vector<vector<ll>> adj( V + 1 );
        for( ll i = 1; i <= E; i += 1 ) {
            ll u, v; cin >> u >> v;
            u += 1; v += 1;
            adj[u].push_back( v );
            adj[v].push_back( u );
        }
        if( isBipartite( V, adj ) ) {
            cout << "BICOLORABLE." << endl;
        }
        else {
            cout << "NOT BICOLORABLE." << endl;
        }
    }
    return 0;
}
