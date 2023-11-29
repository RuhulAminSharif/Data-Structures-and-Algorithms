#include<bits/stdc++.h>
using namespace std;
bool isCyclic(int V, vector<int> adj[]) {
    int inDegree[V]={0};
    for(int node=0; node<V; node++){
        for(auto adjNode: adj[node]){
            inDegree[adjNode]++;
        }
    }
    queue<int>q;
    for(int node=0; node<V; node++){
        if(inDegree[node]==0){
            q.push(node);
        }
    }
    int cnt=0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;
        for(auto adjNode : adj[node]){
            inDegree[adjNode]--;
            if(inDegree[adjNode]==0){
                q.push(adjNode);
            }
        }
    }
    if(cnt==V) return false;
    else return true;
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