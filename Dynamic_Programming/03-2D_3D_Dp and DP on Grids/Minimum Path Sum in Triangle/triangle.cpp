// https://leetcode.com/problems/triangle/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define inf 1e18
const ll mod = 1e9+7;
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int> > dp(n, vector<int>(n, -1));
    for(int i=0; i<n; i++){
        dp[n-1][i] = triangle[n-1][i];
    }
    for(int i = n-2; i>=0; i--) {
        for(int j=i; j>=0; j--) {
            int down = triangle[i][j] + dp[i+1][j];
            int diagright = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down, diagright);
        }
    }
    return dp[0][0];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}
