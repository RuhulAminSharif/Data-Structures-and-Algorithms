https://leetcode.com/problems/minimum-falling-path-sum/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define inf 1e18
const ll mod = 1e9+7;
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int mx = 1e9;
    vector<vector<int>> dp ( n , vector<int> ( m, mx));
    for(int col = 0; col<m; col++ ) {
        dp[n-1][col] = matrix[n-1][col]; 
    }
    for(int row = n-2; row >= 0 ; row-- ) {
        for(int col = 0; col<m; col++) {
            int down  = mx, down_left = mx, down_right = mx;
            down = matrix[row][col] + dp[row+1][col];
            if( col > 0 ) down_left = matrix[row][col] + dp[row+1][col-1];
            if( col < m-1 ) down_right = matrix[row][col] + dp[row+1][col+1];
            dp[row][col] = min(down, min(down_left, down_right));
        }
    }
    int ans = mx;
    for(int i=0; i<m; i++) {
        ans =  min(ans, dp[0][i]);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}
