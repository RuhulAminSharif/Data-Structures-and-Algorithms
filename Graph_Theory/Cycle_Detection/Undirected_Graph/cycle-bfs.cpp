#include<bits/stdc++.h>
using namespace std;
bool detect(int src, vector<int> adj[], bool vis[]){
    vis[src] = true;
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto adjNode : adj[node]){
            if(!vis[adjNode]){
                vis[adjNode] = true;
                q.push({adjNode, node});
            }
            else if(adjNode!=parent){
                return true;
            }
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[]) {
    bool vis[V] = {false};
    for(int i=0; i<V; i++){
        if(!vis[i]){
            if(detect(i, adj, vis)) return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int node, edge; cin >> node >> edge;

    vector<int> adj[node+1];

    for(int i=0; i<edge; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(isCycle(node, adj)) cout << "Cycle detected" << endl;
    else cout << "No cycle" << endl;
    return 0;
}