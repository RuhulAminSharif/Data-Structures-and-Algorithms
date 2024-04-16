/*
Statemet : https://leetcode.com/problems/coin-change-ii/
*/
#include<bits/stdc++.h>
using namespace std;
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp ( n, vector<int> ( amount + 1, 0 ));
    dp[0][0] = 1;
    for( int sum = 1; sum <= amount; sum += 1 ) {
        if( sum % coins[0] == 0 )
            dp[0][sum] = 1;
    }
    
    for( int idx = 1; idx < n; idx += 1 ) {
        dp[idx][0] = 1;
        for( int sum=1; sum <= amount; sum += 1 ) {
            int not_take = dp[idx-1][sum];
            int take = 0;
            if( sum >= coins[idx] ) {
                take = dp[idx][sum-coins[idx]];
            }
            dp[idx][sum] = take + not_take;
        }
    }
    return dp[n - 1][amount];
}
int main() {
    vector<int> coins = {1, 2, 3};
    int target = 4;

    cout << "The total number of ways is " << change(target, coins) << endl;

    return 0;
}