#include <bits/stdc++.h>
using namespace std;
int matrixChainMultiplication(vector<int>& arr, int n) {
    vector<vector<int>> dp ( n+1, vector<int> (n+1, -1));
    for (int i = 0; i <= n; i++) {
        dp[i][i] = 0;
    }
    for( int left = n; left >= 1; left -= 1 ) {
        for( int right = left+1; right <= n; right += 1 ) {
            int res = INT_MAX;
            for( int par = left; par < right; par += 1 ) {
                int temp = arr[left-1] * arr[par] * arr[right] + dp[left][par] + dp[par+1][ right];
                res = min( temp, res) ;
            }
            dp[left][right] = res;
        }
    }
    return dp[1][n];
}
int main()
{
    int n; cin >> n;
    vector<int> arr ( n + 1 ) ;
    for( int i = 0; i <= n; i += 1 ) cin >> arr[i];
    cout << matrixChainMultiplication( arr, n ) << endl;
    return 0;
}
