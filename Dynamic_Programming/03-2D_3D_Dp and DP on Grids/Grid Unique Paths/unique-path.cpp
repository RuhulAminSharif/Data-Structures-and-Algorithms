// https://leetcode.com/problems/unique-paths/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define inf 1e18
const ll mod = 1e9 + 7;
    int uniquePaths(int m, int n) {
        vector<vector<int>>grid(m, vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) grid[i][j] = 1;
                else if(i==0) grid[i][j] += grid[i][j-1];
                else if(j==0) grid[i][j] += grid[i-1][j];
                else grid[i][j] += (grid[i-1][j]+grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}