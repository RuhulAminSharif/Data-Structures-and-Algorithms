#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //taking input of no. of node and edge
    int node, edge;
    cin >> node >> edge;

    // declaring adjacency list
    vector<int> adj[node+1];

    // taking input of the connection of nodes 
    for(int i=0; i<edge; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // printing the connection of the edges in adjacency matrix
    for(int i=0; i<=node; i++){
        cout << "Node " << i << " is connected with ";
        bool fg = false;
        for(auto u : adj[i]){
            fg = true;
            cout << u << " ";
        }
        if(!fg) cout << "none";
        cout << endl;
    }
    
    return 0;
}