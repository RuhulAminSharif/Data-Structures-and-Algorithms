#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mx = 1e5+1;
// declaring adjacency list
vector<int> adj[mx];
// to track whether the node is visited or not
vector<bool>vis(mx);
// to track level of each node
// and level of the each node is the distance from the root node
vector<ll> level(mx);
// to track of parent of any node
vector<ll>parent(mx);
// to store the path
stack<ll>path;
void levelprint(ll node)
{
    // if 1-base indexing then print the level of 1 to node inclusive
    for(ll i=0; i<node; i++){
        cout << i << " " << level[i] << endl;
    }
}
void pathprint()
{
    while((path.size()-1)){
        cout << path.top() << " -> ";
        path.pop();
    }
    cout << path.top() << endl;
}
void bfs(ll start, ll dest)
{
    queue<ll>q;
    // push the initial starting node
    q.push(start);
    // level of root node is always zero
    level[start] = 0;
    // there is no parent of root
    // that's why, we are putting -1
    parent[start] = -1;
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
                // level of any node = level of paren node + 1
                level[xx] = level[x] + 1;
                // as we find 'xx' from the adjacency list of 'x'
                // parent of node 'xx' is node 'x'
                parent[xx] = x;
                vis[xx]=true;
            }
        }
    }
    path.push(dest);
    if(start == dest){
        path.push(start);
        return ;
    }
    while(parent[dest]!=-1){
        path.push(parent[dest]);
        dest = parent[dest];
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

    // taking input of starting and end node
    ll start, dest;
    cin >> start >> dest;

    // bfs function call
    bfs(start, dest);

    cout << endl;
    
    // for printing path
    pathprint();

    cout << endl;
    
    // for level printing of each node
    levelprint(node);
    return 0;
}