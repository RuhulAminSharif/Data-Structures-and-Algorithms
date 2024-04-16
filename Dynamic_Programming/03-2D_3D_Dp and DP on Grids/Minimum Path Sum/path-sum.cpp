// https://leetcode.com/problems/minimum-path-sum/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define inf 1e18
const ll mod = 1e9+7;
int minPathSum(vector<vector<int>>& grid) {
    int sum = 0, row = grid.size(), col = grid[0].size();
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(i==0 && j==0) grid[i][j] = grid[i][j];
            else if(i==0) grid[i][j] += grid[i][j-1];
            else if(j==0) grid[i][j] += grid[i-1][j];
            else grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
        }
    }
    return grid[row-1][col-1];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}
