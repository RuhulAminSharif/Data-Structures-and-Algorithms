#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mx = 1005;
ll adjMat[mx][mx], level[mx][mx];
bool vis[mx][mx];
map<pair<ll,ll>,pair<ll,ll>>parent;
// to store the path
stack<pair<ll,ll>>path;
ll n, m;
/// 8-directional array
ll x[8] = {-1,-1,-1,0,0,1,1,1};
ll y[8] = {-1,0,1,-1,1,-1,0,1};

/*
/// 4-directional array would be
    ll x[4] = {-1,0,0,1};
    ll y[4] = {0,-1,1,0};
*/
void bfs(ll r, ll c)
{
    queue<pair<ll,ll>>q;
    q.push({r,c});
    level[r][c] = 0;
    parent[{r,c}] = {-1,-1};
    vis[r][c]=true;
    // iterate till the queue is empty
    while(!q.empty()){
        // get the topmost element in the queue
        ll i = q.front().first, j = q.front().second;
        q.pop();
        // printing the grid index level wise
        // cout << i << " " << j << endl;
        // traverse for all its neighbours
        for(int k=0; k<8; k++){ // if it is 4-directional grid, then it would run from k=0 to k<4
            // new position using directional array
            ll nr=i+x[k], nc=j+y[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && adjMat[nr][nc]!=-1){ // -1 need to be replaced with incorrect condition
                q.push({nr,nc});
                level[nr][nc] = level[i][j] + 1;
                parent[{nr,nc}] = {i,j};
                vis[nr][nc]=true;
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
    cin >> n >> m;
    // taking input of the connection of nodes
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> adjMat[i][j];
        }
    }
    bfs(0,0); // (0,0) need to be replaced with correct source according to question
    return 0;
}
