#include<bits/stdc++.h>
using namespace std;
bool check(int start, int V, vector<int>adj[], int color[]){
    queue<int>q;
    q.push(start);
    color[start]=0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : adj[node]){
            if(color[it]==-1){
                // since the adjacent node is yet not colored
	            // giving the adjacent node opposite color of the node 
                color[it] = !color[node];
                q.push(it);
            }
            else if(color[it]==color[node]){
                // is the adjacent node having the same color
	            // someone did color it on some other path 
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(int V, vector<int>adj[]){
	int color[V];
	for(int i=0; i<V; i++){
	    color[i] = -1;
	}
	for(int i=0; i<V; i++){
	    if(color[i]==-1){
	        if(check(i, V, adj, color)==false){
	            return false;
	        }
	    }
	}
	return true;
}
int main()
{
    int V, E; cin >> V >> E;
    vector<int>adj[V];
    for(int i=0; i<E; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ans = isBipartite(V, adj);    
	if(ans)cout << "Bipartite Graph or two coloring graph\n";
	else cout << "not bipartie or not two coloring graph\n"; 
}