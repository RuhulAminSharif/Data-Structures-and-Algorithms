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
    vector<pair<int,int>> adj[node+1];

    // taking input of the connection of nodes 
    for(int i=0; i<edge; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }

    // printing the connection of the edges in adjacency matrix
    for(int i=0; i<=node; i++){
        cout << "Node " << i << " ";
        bool fg = false;
        for(auto u : adj[i]){
            fg = true;
            cout << "{" << u.first << "," << u.second << "}";
        }
        if(!fg) cout << "none";
        cout << endl;
    }
    
    return 0;
}