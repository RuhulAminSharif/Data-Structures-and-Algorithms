#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mx = 1e5+5;
// declaring adjacency list
vector<int> adjList[mx];
//declaring adjacency matrix
vector<vector<int>> adjMat(1000, vector<int>(1000,0));
void matrix_to_list(vector<vector<int>>adj, int node)
{
    for(int i=0; i<node; i++){
        for(int j=0; j<node; j++){
            if(adj[i][j] && i != j){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
}
void list_to_matrix(vector<int>adj[], int node)
{
    for(int i=0; i<=node; i++){
        for(auto u : adj[i]){
            adjMat[i][u] = 1;
            adjMat[u][i] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << 1;
    return 0;
}