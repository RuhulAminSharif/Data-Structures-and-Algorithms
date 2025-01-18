#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
bool detect( int src, vector<vector<int>>& adj, vector<bool>& vis ) {
    vis[src] = true;
    queue<pair<int,int>> q; // {node, parent}
    q.push( { src, -1 } );
    while( q.size() > 0 ) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for( int adjNode: adj[node] ) {
            if( vis[adjNode] == false ) {
                q.push( { adjNode, node} );
                vis[ adjNode ] = true;
            }
            else if( adjNode != parent ) {
                return true;
            }
        }
    }
    return false;
}
bool isCycle(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> vis ( V, false );

    for( int i = 0; i < V; i += 1 ) {
        if( vis[i] == false ) {
            if( detect( i, adj, vis) ) return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    for( int i = 0; i < E; i += 1 ){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if( isCycle(adj) ) cout << "has cycle" << endl;
    else cout << "no cycle" << endl;
    return 0;
}
