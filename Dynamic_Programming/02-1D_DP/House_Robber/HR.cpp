// https://leetcode.com/problems/house-robber/
#include<bits/stdc++.h>
using namespace std;
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp (n , 0);
    dp[0] = nums[0];
    if( n >= 2 ) dp[1] = max( nums[1], nums[0] );
    for(int i=2; i<n; i++){
        int pick = nums[i];
        pick += dp[i-2];
        int not_pick = dp[i-1];
        dp[i] = max( pick, not_pick );
    }
    return dp[n-1];
}
int main()
{
    return 0;
}