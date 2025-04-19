#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
vector<vector<int>> sccs;
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
int SCC( vector<vector<int>>& adj, vector<vector<int>>& transposedAdj, int V )
{
    stack<int> finishTime;
    vector<bool> vis( V + 1, false);
    // To fill the stack with vertices in order of their finishing time
    for( int i = 1; i <= V; i += 1 ) {
        if( !vis[i] ) {
            dfs( adj, i, vis, finishTime );
        }
    }
    sccs.clear();
    fill(vis.begin(), vis.end(), false);
    vector<int> componentID( V + 1, 0 );
    int currID = 0;
    while( finishTime.size() > 0 ) {
        int node = finishTime.top();
        finishTime.pop();
        if( !vis[node] ) {
            vector<int> comp;
            reverseDFS( transposedAdj, node, vis, comp);
            currID += 1;
            sccs.push_back( comp );
            for( auto x : comp ) {
                componentID[x] = currID;
            }
        }
    }
    vector<int> inDeg( currID + 1,  0 );
    set<pair<int,int>> isAdded;
    for( int u = 1; u <= V; u += 1 ) {
        for( int v : adj[u] ) {
            int cu = componentID[u];
            int cv = componentID[v];
            if( cu != cv && isAdded.find( {cu, cv} ) == isAdded.end() ) {
                inDeg[ cv ] += 1;
                isAdded.insert( {cu, cv} );
            }
        }
    }
    int sccSrcCount = 0;
    for( int i = 1; i <= currID; i += 1 ) {
        if( inDeg[i] == 0 ) {
            sccSrcCount += 1;
        }
    }
    return sccSrcCount;
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
        // number of source that has no incoming edge
        cout << SCC( adj, transposedAdj, V ) << endl;
        /**
            how many scc:
            cout << sccs.size() << endl;
            cout << "SCCs are:" << endl;
            for (int i = 0; i < sccs.size(); ++i) {
                cout << "Component " << i + 1 << ": ";
                for (int node : sccs[i]) {
                    cout << node << " ";
                }
                cout << endl;
            }
        **/
    }
    return 0;
}
// UVA-> p11770 - Lighting Away
