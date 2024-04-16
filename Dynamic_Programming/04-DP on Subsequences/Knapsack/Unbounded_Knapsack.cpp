/*
Given a set of N items, each with a weight and a value, represented by the array w and val respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of time.
*/
#include<bits/stdc++.h>
using namespace std;
int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> dp(N, vector<int>(W + 1, 0));
        
    for (int i = wt[0]; i <= W; i++) {
        dp[0][i] = val[0] + dp[0][i-wt[0]];
    }
    
    for (int idx = 1; idx < N ; idx++) {
        for (int cap = 0; cap <= W; cap++) {
            int not_take = 0 + dp[idx - 1][cap];
            int take = INT_MIN;
            if (wt[idx] <= cap) take = val[idx] + dp[idx][cap - wt[idx]]; 
                    
            dp[idx][cap] = max(not_take, take);
        }
    }
    
    return dp[N - 1][W]; 
}
int main()
{
    int N, W; 
    cin >> N >> W;
    int val[N], wt[N];
    for( int i=0; i < N; i++) cin >> val[i];
    for( int i=0; i < N; i++) cin >> wt[i];
    cout << knapSack(N, W, val, wt) << endl;
}