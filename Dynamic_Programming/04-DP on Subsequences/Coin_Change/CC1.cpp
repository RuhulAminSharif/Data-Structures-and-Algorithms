/*
Statemet : https://leetcode.com/problems/coin-change/
*/
#include<bits/stdc++.h>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp ( n, vector<int> ( amount + 1, 1e9 ));
    for( int sum = 0; sum <= amount; sum += 1 ) {
        if( sum % coins[0] == 0 )
            dp[0][sum] = sum/coins[0];
        }
    for( int idx = 1; idx < n; idx += 1 ) {
        for( int sum=0; sum <= amount; sum += 1 ) {
            int not_take = dp[idx-1][sum];
            int take = 1e9;
            if( sum >= coins[idx] ) {
                take = 1 + dp[idx][sum-coins[idx]];
            }
            dp[idx][sum] = min(take, not_take);
        }
    }
    int ans = dp[n - 1][amount];
    if (ans >= 1e9) ans = -1;
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3};
    int T = 7;
    
    int result = coinChange(arr, T);

    cout << "The minimum number of coins required to form the target sum is " << result << endl;
    
    return 0;
}