#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mx = 1e5+5;
// declaring adjacency list
// to store the given directed graph
vector<int> adj[mx];
// declaring adjacency list
// to store reverse order directed graph of given graph
vector<int> tra[mx];
// to track whether the node is visited or not for first dfs
vector<bool> vis(mx);
// to track whether the node is visited or not for second dfs
vector<bool> vis1(mx);
// to store the node according to their ending time
stack<int>st;
// dfs for given directed graph
void dfs(int node)
{
    vis[node] = true;
    // traverse for all its neighbours
    for(auto x : adj[node]){
        // if the neighbour has previously not been visited, 
        // recursive call to dfs again to go depth
        if(!vis[x]){
            dfs(x);
        }
    }
    st.push(node);
}
// dfs for transpose graph of the given graph
void dfs1(int node)
{
    vis1[node] = true;
    // printing the strongly connected components
    cout << node << " ";
    // traverse for all its neighbours
    for(auto x : tra[node]){
        // if the neighbour has previously not been visited, 
        // recursive call to dfs again to go depth
        if(!vis1[x]){
            dfs1(x);
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
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        tra[v].push_back(u);
    }

    for(int i=0; i<node; i++){ // if 1-base indexing then 1 to node
        if(!vis[i]){
            dfs(i);
        }
    }
    // to count number of strongly connectedly components
    int cnt = 0;
    while(st.size()){
        int x = st.top();
        if(!vis1[x]){
            cnt += 1;
            dfs1(x);
            cout << endl;
        }
        st.pop();
    }
    cout << "No. strongly connected components : " << cnt << endl;
    return 0;
}