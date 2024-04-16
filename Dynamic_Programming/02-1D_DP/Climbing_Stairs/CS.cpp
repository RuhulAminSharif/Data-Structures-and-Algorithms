// https://leetcode.com/problems/climbing-stairs/
#include<bits/stdc++.h>
using namespace std;
int climbStairs(int n) {
    vector<int>dp(n+1,0);
    // int dp[n+1]={0};
    dp[0] = dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main()
{
    return 0;
}