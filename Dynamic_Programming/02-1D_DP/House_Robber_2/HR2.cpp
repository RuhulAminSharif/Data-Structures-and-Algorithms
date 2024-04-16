// https://leetcode.com/problems/house-robber-ii/
#include<bits/stdc++.h>
using namespace std;
    int solve(vector<int>& nums){
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
    int rob(vector<int>& nums) {
        int n = nums.size();
        if( n == 1 ) return nums[0];
        vector<int> v1, v2;
        for(int i=0; i<n; i++){
            if( i != 0 ) v2.push_back( nums[i] );
            if( i != n-1 ) v1.push_back( nums[i] );
        }
        return max( solve(v1), solve(v2) );
    }
int main()
{
    return 0;
}