// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define inf 1e18
const ll mod = 1e9+7;
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    int maxTransaction = k;
    int buyState = 2;
    vector<vector<vector<int>>> dp ( n+1, vector<vector<int>> ( buyState, vector<int> ( maxTransaction+1 , 0 ) ) );
    for( int idx = n-1; idx >= 0 ; idx -= 1 ) {
        for( int buy = 0; buy <= 1; buy += 1 ) {
            for( int cap = 1; cap <= maxTransaction; cap += 1 ) {
                int profit = 0;
                if( buy ) {
                    profit = max( -prices[idx] + dp[idx+1][0][cap] , dp[idx+1][1][cap]);
                } else {
                    profit = max( prices[idx] + dp[idx+1][1][cap-1] , dp[idx+1][0][cap]);
                }
                dp[idx][buy][cap] = profit;
            }
        }
    }
    return dp[0][1][k];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}
