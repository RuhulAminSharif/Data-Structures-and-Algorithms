#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mx = 1e5+1;
// declaring adjacency list
vector<int> adj[mx];
// to track whether the node is visited or not
vector<bool>vis(mx);
void bfs(ll start)
{
    queue<ll>q;
    // push the initial starting node
    q.push(start);
    vis[start]=true;
    // iterate till the queue is empty
    while(!q.empty()){
        // get the topmost element in the queue
        int x = q.front();
        q.pop();
        // printing the node level wise
        // cout << x << " ";
        // traverse for all its neighbours
        for(auto xx : adj[x]){
            // if the neighbour has previously not been visited, 
            // store in Q and mark as visited 
            if(!vis[xx]){
                q.push(xx);
                vis[xx]=true;
            }
        }
    }
    return ;
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
        adj[v].push_back(u);
    }

    int cnt=0; // to count number of connected components
    for(int i=1; i<=node; i++){
        if(!vis[i]){
            cnt += 1;
            bfs(i);
        }
    }
    cout << cnt << endl;
    return 0;
}