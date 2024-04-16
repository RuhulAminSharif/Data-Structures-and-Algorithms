// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define inf 1e18
const ll mod = 1e9+7;
int maxProfit(vector<int>& prices) {
    int maxProfit = 0, mn = prices[0], len = prices.size();
    for(int i=1; i < len; i += 1 ){
        int currProfit = prices[i]-mn;
        maxProfit = max(maxProfit, currProfit);
        mn = min (mn, prices[i]);
    }
    return maxProfit;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}