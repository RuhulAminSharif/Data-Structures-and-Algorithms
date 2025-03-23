#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int source)
{
    int V = adj.size();
    vector<int> dist( V, 1e9 );
    set<pair<int, int>> st;
    st.insert( {0, source} );
    dist[source] = 0;
    while( st.size() > 0 ) {
        auto it = *(st.begin());
        int node = it.second;
        st.erase(st.begin());
        for( auto it : adj[node] ) {
            int adjNode = it.first;
            int adjWeight = it.second;
            int nextWeight = dist[node] + adjWeight;
            if( nextWeight < dist[adjNode] ) {
                st.erase( {dist[adjNode], adjNode} );
                dist[adjNode] = nextWeight;
                st.insert( { nextWeight, adjNode } );
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int V, E; cin >> V >> E;
    vector<vector<pair<int, int>>> adj ( V ); /// node -> node, weight
    for( ll i = 0; i < E; i += 1 ) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back( { v, w } );
        adj[v].push_back( { u, w } );
    }
    ll src; cin >> src;
    vector<int> dist = dijkstra(adj, src);
    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < V; i += 1 ) {
        cout << "Node " << i << ": " << dist[i] << "\n";
    }
    return 0;
}