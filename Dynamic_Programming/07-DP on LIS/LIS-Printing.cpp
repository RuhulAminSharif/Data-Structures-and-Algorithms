#include<bits/stdc++.h>
using namespace std;
vector<int> LIS( vector<int>& arr ) 
{
    int n = arr.size();
    vector<int> dp ( n + 1 , 1 ), hash ( n + 1 , 1 ) ;
    for( int idx= 0; idx < n; idx += 1 ) {
        hash[idx] = idx;
        for( int prev_idx = 0; prev_idx < idx; prev_idx += 1 ) {
            if( arr[prev_idx] < arr[idx] && 1 + dp[prev_idx] > dp[idx] ) {
                dp[idx] = 1 + dp[prev_idx];
                hash[idx] = prev_idx;
            }
        }
    }
    int last_idx = -1, maxLen = -1;
    for( int idx = 0; idx < n; idx += 1 ) {
        if( dp[idx] > maxLen ) {
            maxLen = dp[idx];
            last_idx = idx;
        }
    }
    vector<int> lis (maxLen);
    int idx = maxLen - 1;
    lis[idx--] = arr[last_idx];
    while( hash[last_idx] != last_idx ) {
        last_idx = hash[last_idx];
        lis[idx--] = arr[last_idx];
    }
    return lis;
}
int main()
{
    vector<int> arr = {10,9,2,5,3,7,101,18};
    vector<int> ans = LIS(arr);
    for( auto it : ans ) cout << it << " ";
    cout << endl;
}