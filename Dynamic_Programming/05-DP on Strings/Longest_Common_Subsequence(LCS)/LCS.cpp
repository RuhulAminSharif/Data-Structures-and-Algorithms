// https://leetcode.com/problems/longest-common-subsequence/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define inf 1e18
const ll mod = 1e9 + 7;
string longestCommonSubsequence(string s, string t)
{
    ll n = s.size(), m = t.size();
    vector<vector<ll>> dp(n + 5, vector<ll>(m + 5, 0));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    string ans = "";
    ll i = n, j = m;
    while (i >= 1 && j >= 1) {
        if (s[i - 1] == t[j - 1]) {
            ans += s[i - 1];
            i -= 1, j -= 1;
        } else {
            if (dp[i - 1][j] >= dp[i][j - 1]) i -= 1;
            else j -= 1;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    cin >> s >> t;
    string LCS = longestCommonSubsequence(s, t);
    cout << "Length of longest common subsequence : " << LCS.size() << endl;
    cout << "Longest Common Subsequence : " << LCS << endl;
    return 0;
}
