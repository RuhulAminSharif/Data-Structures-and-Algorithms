#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
const int mx = 1e5+5;
// declaring adjacency list to store the graph
// here, pair.fist->node, pair.second->cost
vector<pair<ll,ll>>adj[mx];
// using a minimum prority queue to implement the algo
// here, pair.first->cost, pair.second->node  
priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
// to store the distance of nodes from parent node
vector<ll> dis(mx, LLONG_MAX);
// to track parent of any node
vector<ll> parent(mx, -1);

void path_print(ll node)
{
    if(parent[node]==-1){
        cout << node << " ";
        return;
    }
    path_print(parent[node]);
    cout << node << " ";
}
void dijkstra(ll source)
{
    pq.push({0,source});
    dis[source]=0;
    while(pq.size()){
        ll node = pq.top().second;
        ll cost = pq.top().first;
        pq.pop();
        for(auto it : adj[node]){
            if(cost+it.second<dis[it.first]){
                dis[it.first] = cost+it.second;
                pq.push({cost+it.second, it.first});
                parent[it.first] = node;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //taking input of no. of node and edge
    int node, edge;
    cin >> node >> edge;

    // taking input of the connection of nodes 
    for(int i=0; i<edge; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    ll source; cin >> source;
    dijkstra(source);
    
    // printing path from source
    for(int i = 0 ; i < node ; i++ ){
        cout << source << " to " << i <<" : ";
        path_print(i);
        cout << endl;
    }

    // printing distance form source
    for(int i=0; i<node; i++){
        cout << source << " to " << i << " distance : " << dis[i] << " " << endl;
    }

}
