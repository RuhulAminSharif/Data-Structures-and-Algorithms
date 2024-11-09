#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mx = 1005;
ll adjMat[mx][mx], n, m;
bool vis[mx][mx];
/// 8-directional array
ll x[8] = {-1,-1,-1,0,0,1,1,1};
ll y[8] = {-1,0,1,-1,1,-1,0,1};

/*
/// 4-directional array would be
    ll x[4] = {-1,0,0,1};
    ll y[4] = {0,-1,1,0};
*/
void dfs(ll r, ll c)
{
    vis[r][c]=true;
    // cout << r << " " << c << endl;
    // traverse for all its neighbours
    for(int k=0; k<8; k++){ // if it is 4-directional grid, then it would run from k=0 to k<4
        // new position using directional array
        ll nr=r+x[k], nc=c+y[k];
        if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && adjMat[nr][nc]!=-1){ // -1 need to be replaced with incorrect condition
            dfs(nr,nc);
        }
    }
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
    dfs(0,0); // (0,0) need to be replaced with correct source according to question
    return 0;
}