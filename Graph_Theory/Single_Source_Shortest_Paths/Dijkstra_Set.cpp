#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mx = 1e5+5;
// declaring adjacency list to store the graph
// here, pair.fist->node, pair.second->cost
vector<pair<int,int>>adj[mx];
// using set data structure to implement the algo
// here, pair.first->cost, pair.second->node  
set<pair<ll,ll>>st;
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
    st.insert({0, source});
    dis[source] = min(dis[source], 0LL);
    while(st.size()){
        ll node = st.begin()->second;
        ll cost = st.begin()->first;
        st.erase(st.begin());
        for(auto it : adj[node]){
            if(cost+it.second<dis[it.first]){
                if(dis[it.first]!=LLONG_MAX){
                    st.erase({dis[it.first], it.first});
                }
                dis[it.first]=cost+it.second;
                st.insert({cost+it.second,it.first});
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