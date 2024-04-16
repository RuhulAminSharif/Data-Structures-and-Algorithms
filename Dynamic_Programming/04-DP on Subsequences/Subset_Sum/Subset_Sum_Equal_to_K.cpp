/*
    Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum

    
*/
#include<bits/stdc++.h>
using namespace std;
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        for(int i=0; i<n; i++) dp[i][0] = true;
        if ( arr[0] <= sum ) {
            dp[0][arr[0]] = true;
        }
        for(int idx = 1; idx < n; idx += 1  ) {
            for( int target=1; target<=sum; target += 1 ) {
                bool not_take = dp[idx-1][target];
                bool take = false;
                if( target >= arr[idx] ) take = dp[idx-1][target-arr[idx]];
                dp[idx][target] = take || not_take;
            }
        }
        return dp[n-1][sum];
    }
};
int main()
{
    int t; cin >> t;
    while( t-- ) {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for( int i=0; i<N; i++) {
            cin >> arr[i];
        }
        cin >> sum;
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
}