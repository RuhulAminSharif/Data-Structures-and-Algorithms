// https://leetcode.com/problems/shortest-common-supersequence/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
string shortestCommonSupersequence(string str1, string str2) {
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp ( n+1, vector<int> ( m+1 , 0 ) );

    for( int i=1; i <= n; i += 1 ) {
        for( int j=1; j <= m; j += 1 ) {
            if( str1[i-1] == str2[j-1] ) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max( dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int i = n, j = m;
    string ans = "";
    while( i >= 1 && j >= 1 ) {
        if( str1[i-1] == str2[j-1] ) {
            ans += str1[i-1];
            i -= 1;
            j -= 1;
        } else if( dp[i-1][j] >= dp[i][j-1] ) {
            ans += str1[i-1];
            i -= 1;
        } else {
            ans += str2[j-1];
            j -= 1;
        }
    }
    while( i >= 1 ) {
        ans += str1[i-1];
        i -= 1;
    }
    while( j >= 1 ) {
        ans += str2[j-1];
        j -= 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a, b; cin >> a >> b;
    cout << shortestCommonSupersequence(a,b) << endl;
    return 0;
}
