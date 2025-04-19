#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
void bfs_01( int source, vector<vector<pair<int,int>>>& adj)
{
    int V = adj.size();
    vector<int> dist( V, INT_MAX );
    deque<int> dq;
    dq.push_front( source );
    dist[source] = 0;
    while( dq.size() > 0 ) {
        int node = dq.front();
        dq.pop_front();
        for( auto [ adjNode, weight ] : adj[node] ) {
            int nextDist = dist[node] + weight;
            if( nextDist < dist[adjNode] ) {
                dist[adjNode] = nextDist;
                if( weight == 0 ) { /// compare with min given weight
                    dq.push_front( adjNode );
                }
                else {
                    dq.push_back( adjNode );
                }
            }
        }
    }
    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < V; i += 1 ) {
        cout << "Node " << i << ": " << dist[i] << "\n";
    }
    return ;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int,int> > > adj(V);
    for( int i = 0; i < E; i += 1 ){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back( {v,w} );
        adj[v].push_back( {u,w} );
    }
    bfs_01(0, adj);
    return 0;
}
