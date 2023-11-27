#include<bits/stdc++.h>
using namespace std;
bool dfscheck(int node, vector<int> adj[], bool vis[], bool pathVis[]){
    vis[node]=true;
    pathVis[node]=true;
    for(auto adjNode : adj[node]){
        if(!vis[adjNode]){
            if(dfscheck(adjNode, adj, vis, pathVis)){
                return true;
            }
        }
        else if(pathVis[adjNode]){
            return true;
        }
    }
    pathVis[node]=false;
    return false;
}
bool isCyclic(int V, vector<int> adj[]) {
    bool vis[V] ={false}, pathVis[V]={false};
        
    for(int i=0; i<V; i++){
        if(!vis[i]){
            if(dfscheck(i, adj, vis, pathVis)){
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int V, E; cin >> V >> E;
    vector<int>adj[V];
    for(int i=0; i<E; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    if(isCyclic(V, adj)){
        cout << "Cyclic" << endl;
    }
    else{
        cout << "Not cyclic" << endl;
    }
    return 0;
}