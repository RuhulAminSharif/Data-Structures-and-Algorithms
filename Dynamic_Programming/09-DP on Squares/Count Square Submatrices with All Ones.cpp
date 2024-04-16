// https://leetcode.com/problems/count-square-submatrices-with-all-ones/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define inf 1e18
const ll mod = 1e9+7;
int countSquares(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp ( n, vector<int> ( m, 0 ) ) ;
    for( int i = 0; i < n; i += 1 ) {
        dp[i][0] = matrix[i][0];
    }
    for( int j = 0; j < m; j += 1 ) {
        dp[0][j] = matrix[0][j]; 
    }
    for( int i = 1; i < n; i += 1 ) {
        for( int j = 1; j < m; j += 1 ) {
            if( matrix[i][j] ) {
                dp [i][j] = 1 + min ( dp[i-1][j-1], min ( dp[i-1][j], dp[i][j-1]) ) ;
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    int ans = 0;
    for( int i = 0; i < n; i += 1 ) {
        for( int j = 0; j < m; j += 1 ) {
            ans += dp[i][j];
        }
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
