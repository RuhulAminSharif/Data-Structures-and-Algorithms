#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int>adj[], int vis[], stack<int>& st){
    vis[node]=1;
    for(auto adjNode : adj[node]){
        if(!vis[adjNode]){
            dfs(adjNode, adj, vis, st);
        }
    }
    st.push(node);
}
vector<int> topoSort(int V, vector<int> adj[]) 
{
	int vis[V]={0};
	stack<int>st;
	for(int i=0; i<V; i++){
	    if(!vis[i]){
	        dfs(i, adj, vis, st);
	    }
	}
    vector<int>ans;
	while(!st.empty()){
	    ans.push_back(st.top());
	    st.pop();
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