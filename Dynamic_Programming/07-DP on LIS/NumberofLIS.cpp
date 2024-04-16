// https://leetcode.com/problems/number-of-longest-increasing-subsequence/
#include<bits/stdc++.h>
using namespace std;
int findNumberOfLIS(vector<int>& arr) {
    int len = arr.size();
    vector<int> dp(len+1, 1 ), cnt (len +1 , 1) ;
    vector<int> temp;
    temp.push_back(arr[0]);
    int lis = 1;
    for( int i = 1; i < len; i += 1 ) {
        for( int j = 0; j <= i; j += 1 ) {
            if( arr[j] < arr[i ] && 1 + dp[j] > dp[i] ) {
                dp[i] = 1 + dp[j];
                cnt[i] = cnt[j];
            }
            else if( arr[j] < arr[i ] && 1 + dp[j] == dp[i] ) {
                cnt[i] += cnt[j];
            }
        }
        lis = max(lis, dp[i]);
    }
    int ans = 0;
    for( int i = 0; i < len; i += 1 ) {
        ans += ( dp[i] == lis ) ? cnt[i] : 0 ;
    }
    return ans;
}
int main()
{

}
