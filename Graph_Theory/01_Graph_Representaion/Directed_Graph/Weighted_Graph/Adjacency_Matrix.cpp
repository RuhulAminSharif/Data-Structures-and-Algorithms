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

    // declaring adjacency matrix
    vector<vector<int>> adj(node+1, vector<int>(node+1,0));

    // taking input of the connection of nodes and weight
    for(int i=0; i<edge; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u][v] = w;
    }

    // printing the connection of the edges in adjacency matrix
    for(int i=0; i<=node; i++){
        for(int j=0; j<=node; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}