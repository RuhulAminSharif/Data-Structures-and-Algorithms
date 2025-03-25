#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
const ll inf = 1e18;
ll node, edge;
void bellmanFord(vector<vector<ll>>& edgeList, ll src, ll dst )
{
    vector<ll> dist( node + 1, inf );
    dist[src] = 0LL;
    vector<ll> parent( node + 1, 0 );
    parent[src] = src;
    bool hasCycle = false;
    ll cycleNode = -1;
    for( ll i = 1; i <= node; i += 1 ) {
        for( ll j = 0; j < edge; j += 1 ) {
            ll u = edgeList[j][0];
            ll v = edgeList[j][1];
            ll w = edgeList[j][2];
            if( dist[u] + w < dist[v] ) {
                dist[v] = dist[u] + w ;
                parent[v] = u;
                if( i == node ) {
                    hasCycle = true;
                    cycleNode = v;
                }
            }
        }
    }
    if( hasCycle ) {
        for( ll i = 1; i <= node; i += 1 ) {
            cycleNode = parent[cycleNode];
        }
        vector<ll> cycle;
        for( ll curr = cycleNode; ; curr = parent[curr] ){
            cycle.push_back( curr );
            if( curr == cycleNode && cycle.size() > 1 ) {
                break;
            }
        }
        reverse( cycle.begin(), cycle.end() );
        cout << "YES" << endl;
        for( ll i = 0; i < cycle.size(); i += 1 ) {
            cout << cycle[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "NO" << endl;
        vector<ll> path;
        path.push_back( dst );
        ll node = dst;
        while( parent[node] != node ) {
            path.push_back( parent[node] );
            node = parent[node];
        }
        path.push_back( src );
        reverse( path.begin(), path.end() );
        for( ll i = 0; i < path.size(); i += 1 ) {
           ///  cout << path[i] << " ";
        }
    }
    return ;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> node >> edge;
    vector<vector<ll>> edgeList( edge, vector<ll>(3) );
    for( ll i = 0; i < edge ; i += 1 ) {
        ll u, v, w; cin >> u >> v >> w;
        edgeList[i][0] = u;
        edgeList[i][1] = v;
        edgeList[i][2] = w;
    }
    bellmanFord( edgeList, 1, node );
    return 0;
}
