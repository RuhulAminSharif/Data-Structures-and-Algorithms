// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define inf 1e18
const ll mod = 1e9+7;
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int buyState = 2;
    vector<vector<int>> dp ( n+2, vector<int> ( buyState, 0 )  );
    for( int idx = n-1; idx >= 0 ; idx -= 1 ) {
        for( int buy = 0; buy <= 1; buy += 1 ) {
            int profit = 0;
            if( buy ) {
                profit = max( -prices[idx] + dp[idx+1][0] , dp[idx+1][1]);
            } else {
                profit = max( prices[idx] + dp[idx+2][1] , dp[idx+1][0]);
            }
            dp[idx][buy] = profit;
        }
    }
    return dp[0][1];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}
