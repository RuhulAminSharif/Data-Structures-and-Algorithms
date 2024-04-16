// https://leetcode.com/problems/delete-operation-for-two-strings/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define inf 1e18
const ll mod = 1e9+7;
int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp ( n + 1, vector<int> ( m + 1 , 0 ) ) ;

    for( int i = 1; i <= n; i += 1 ) {
        for( int j = 1; j <= m; j += 1 ) {
            if( word1[i-1] == word2[j-1] ) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return n + m - dp[n][m] * 2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}
