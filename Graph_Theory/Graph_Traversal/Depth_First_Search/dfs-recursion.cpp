#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mx = 1e5+5;
// declaring adjacency list
vector<int> adj[mx];
// to track whether the node is visited or not
vector<bool>vis(mx);
void dfs(int node)
{
    vis[node] = true;
    //printing the node depth wise
    cout << node << " ";
    //traverse for all its neighbour
    for(auto x : adj[node]){
        // if the neighbour has previously not been visited, 
        // recursive call to dfs again to go depth
        if(!vis[x]){
            dfs(x);
        }
    }
    return ;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //taking input of no. of node and edge
    int node, edge;
    cin >> node >> edge;

    // taking input of the connection of nodes 
    for(int i=0; i<edge; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); //this line won't be added for directed graph
    }

    // taking input of starting node of dfs traversal
    ll start;
    cin >> start;

    // dfs function call
    dfs(start);

    cout << endl;

    return 0;
}