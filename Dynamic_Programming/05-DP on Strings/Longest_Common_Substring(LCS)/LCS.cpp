#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define inf 1e18
const ll mod = 1e9 + 7;
string longestCommonSubstring(string s, string t)
{
    ll n = s.size(), m = t.size();
    vector<vector<ll>> dp(n + 5, vector<ll>(m + 5, 0));
    ll row = -1, col = -1, mx_len = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (dp[i][j] > mx_len) {
                    mx_len = dp[i][j], row = i, col = j;
                }
            }
            else    dp[i][j] = 0;
        }
    }
    string ans = "";
    while (row >= 1 && col >= 1 && dp[row][col] > 0) {
        ans += s[row - 1];
        row -= 1, col -= 1;
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
    string LCS = longestCommonSubstring(s, t);
    cout << "Length of longest common substring : " << LCS.size() << endl;
    cout << "Longest Common Substring : " << LCS << endl;
    return 0;
}
