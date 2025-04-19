#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
const ll inf = 1e18;
ll node, edge;
vector<vector<ll>> floydWarshall(vector<vector<ll>>& adjMat )
{
    vector<vector<ll>> dist( node + 1, vector<ll> ( node + 1, inf ));
    for( ll i = 1; i <= node; i += 1 ) {
        for( ll j = 1; j <= node; j += 1 ) {
            if( i == j ) dist[i][j] = 0;
            else if (adjMat[i][j] != 0) dist[i][j] = adjMat[i][j];
        }
    }
    for( ll k = 1; k <= node; k += 1 ) {
        for( ll i = 1; i <= node; i += 1 ) {
            for( ll j = 1; j <= node; j += 1 ) {
                if( dist[i][k] != inf && dist[k][j] != inf ) {
                    dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
                }
            }
        }
    }
    return dist;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> node >> edge;
    vector<vector<ll>> adjMat( node + 1, vector<ll>( node + 1, inf ) );
    for( ll i = 1; i <= edge; i += 1 ) {
        ll u, v, w; cin >> u >> v >> w;
        adjMat[u][v] = w;
    }
    vector<vector<ll>> dist = floydWarshall( adjMat );
    ll q; cin >> q;
    while( q-- ) {
        ll u, v; cin >> u >> v;
        if( dist[u][v] == inf ) cout << -1 << endl;
        else cout << dist[u][v] << endl;
    }
    return 0;
}
