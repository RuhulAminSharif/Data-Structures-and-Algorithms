#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"

void dfs( vector<vector<int>>& adj, int node, vector<bool>& vis, stack<int>& finishTime )
{
    vis[node] = true;
    for( int adjNode : adj[node] ) {
        if( !vis[adjNode] ) {
            dfs( adj, adjNode, vis, finishTime );
        }
    }
    finishTime.push( node );
    return ;
}
void reverseDFS( vector<vector<int>>& transposedAdj, int node, vector<bool>& vis, vector<int>& comp )
{
    vis[node] = true;
    comp.push_back( node );
    for( int adjNode : transposedAdj[node] ) {
        if( !vis[adjNode] ) {
            reverseDFS( transposedAdj, adjNode, vis, comp );
        }
    }
    return ;
}
vector<vector<int>> SCC( vector<vector<int>>& adj, vector<vector<int>>& transposedAdj, int V )
{
    stack<int> finishTime;
    vector<bool> vis( V + 1, false);
    // To fill the stack with vertices in order of their finishing time
    for( int i = 1; i <= V; i += 1 ) {
        if( !vis[i] ) {
            dfs( adj, i, vis, finishTime );
        }
    }
    vector<vector<int>> sccs;
    fill(vis.begin(), vis.end(), false);
    while( finishTime.size() > 0 ) {
        int node = finishTime.top();
        finishTime.pop();
        if( !vis[node] ) {
            vector<int> comp;
            reverseDFS( transposedAdj, node, vis, comp );
            sccs.push_back( comp );
        }
    }
    return sccs;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1; cin >> t;
    for( ll test = 1; test <= t; test += 1 ) {
        cout << "Case " << test << ": ";
        int V, E; cin >> V >> E;
        vector<vector<int>> adj ( V + 1 );
        vector<vector<int>> transposedAdj ( V + 1 );
        for( ll i = 0; i < E; i += 1 ) {
            ll u, v; cin >> u >> v;
            adj[u].push_back( v );
            transposedAdj[v].push_back( u );
        }
        vector<vector<int>> sccs = SCC( adj, transposedAdj, V );
        cout << sccs.size() << endl;
        for( int i = 0; i < sccs.size(); i += 1 ) {
            for( auto c : sccs[i] ) {
                cout << c << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
