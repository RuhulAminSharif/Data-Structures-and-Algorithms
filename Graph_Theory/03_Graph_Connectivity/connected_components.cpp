#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
vector<vector<int>> adj;
vector<bool> vis;
vector<int> comp;
void dfs(int node)
{
    vis[node] = true;
    comp.push_back( node );
    for(auto x : adj[node]){
        if( !vis[x] ){
            dfs(x);
        }
    }
    return ;
}
vector<vector<int>> find_comps( int N )
{
    vector<vector<int>> allComponents;
    for( int i = 0; i < N; i += 1 ) {
        if( vis[i] == 0 ) {
            comp.clear();
            dfs(i);
            sort( comp.begin(), comp.end() ); /// if answer required to store in sorted order
            allComponents.push_back(comp);
        }
    }
    return allComponents;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int node, edge;
    cin >> node >> edge;
    adj.resize( node );
    vis.resize( node + 1, false );
    for( int i = 0; i < edge; i += 1 ){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> cc = find_comps(node);
    cout << cc.size() << endl; /// to know number of connected components
    for( int i = 0; i < cc.size(); i += 1 ) {
        for( int j = 0; j < cc[i].size(); j += 1 ) {
            cout << cc[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
