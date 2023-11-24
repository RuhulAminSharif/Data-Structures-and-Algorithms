#include<bits/stdc++.h>
using namespace std;
bool check(int node, vector<int>adj[], int color[], int C){
    color[node] = C;
    for(auto it : adj[node]){
        if(color[it]==-1){
            if(check(it, adj, color, !C)==false){
                return false;
            }
        }
        else if(color[it]==color[node]){
            return false;
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
	        int C=0;
	        if(check(i, adj, color, C)==false){
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