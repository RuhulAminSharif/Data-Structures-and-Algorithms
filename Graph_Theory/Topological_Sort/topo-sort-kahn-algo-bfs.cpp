#include<bits/stdc++.h>
using namespace std;
vector<int> topoSort(int V, vector<int> adj[]) 
{
    int inDegree[V]={0};
    
    for(int node=0; node<V; node++){
        for(auto adjNode : adj[node]){
            inDegree[adjNode]++;
        }
    }
    queue<int>q;
    for(int node=0; node<V; node++){
        if(inDegree[node]==0){
            q.push(node);
        }
    }
    vector<int>ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto adjNode : adj[node]){
            inDegree[adjNode]--;
            if(inDegree[adjNode]==0){
                q.push(adjNode);
            }
        }
    }
    return ans;
}
int main()
{
    int V, E; cin >> V >> E;
    vector<int>adj[V];
    for(int i=0; i<E; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int>ans = topoSort(V, adj);
    for(auto it : ans) cout << it << " ";
    cout << endl;
    return 0;
}