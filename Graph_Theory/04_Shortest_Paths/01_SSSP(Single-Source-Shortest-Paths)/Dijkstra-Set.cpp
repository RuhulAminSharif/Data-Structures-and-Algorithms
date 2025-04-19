#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
#define inf 1e18
void dijkstra(vector<vector<pair<ll, ll>>> &adj, ll src, ll dst)
{
    ll node = adj.size();
    vector<ll> dist( node + 1, inf );
    vector<ll> parent( node + 1, 0 );
    set<pair<ll, ll>> st;
    st.insert( {0, src} );
    dist[src] = 0;
    parent[src] = -1;
    while( st.size() > 0 ) {
        auto it = *(st.begin());
        ll node = it.second;
        st.erase(st.begin());
        for( auto it : adj[node] ) {
            ll adjNode = it.first;
            ll adjWeight = it.second;
            ll nextWeight = dist[node] + adjWeight;
            if( nextWeight < dist[adjNode] ) {
                st.erase( {dist[adjNode], adjNode} );
                dist[adjNode] = nextWeight;
                parent[adjNode] = node;
                st.insert( { nextWeight, adjNode } );
            }
        }
    }
    vector<ll> path;
    if( dist[dst] == inf ) {
        path.push_back(-1);
    }
    else {
        path.push_back(dst);
        ll node = dst;
        while( parent[node] != -1 ) {
            path.push_back( parent[node] );
            node = parent[node];
        }
    }
    reverse( path.begin(), path.end() );
    for( ll i = 0; i < path.size(); i += 1 ) {
        cout << path[i] << " ";
    }
    cout << endl;

    for (int i = 1; i <= node; i += 1 ) {
        cout << "Node " << i << ": " << dist[i] << "\n";
    }
    return ;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll node, edge; cin >> node >> edge;
    vector<vector<pair<ll, ll>>> adj ( node + 1 );
    for( ll i = 1; i <= edge ; i += 1 ) {
        ll u, v, w; cin >> u >> v >> w;
        if( u != v ) {
            adj[u].push_back( { v, w } );
            adj[v].push_back( { u, w } );
        }
    }
    dijkstra(adj, 1, node);
    return 0;
}
