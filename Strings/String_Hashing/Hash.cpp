#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int N = 1e7;
const int mod1 = 1e9 + 7, mod2 = 1e9 + 9;
const int base1 = 37, base2 = 53;
int ibase1, ibase2;
vector<pair<ll, ll>> pw(N+5), inv_pw(N+5);
long long mod_pow(long long b, long long p, const int mod) {
    long long r = 1 % mod;
    b %= mod;
    if (b < 0)    b += mod;
    while (p) {
        if (p & 1) {
            r = (long long)(r * b) % mod;
        }
        b = (long long)(b * b) % mod;
        p >>= 1;
    }
    return r;
}
void pow_calc()
{
    pw[0] = {1LL, 1LL};
    for (ll i = 1; i <= N; i += 1) {
        pair<ll, ll> curr;
        curr.first = 1LL * pw[i - 1].first * base1 % mod1;
        curr.second = 1LL * pw[i - 1].second * base2 % mod2;
        pw[i] = curr;
    }

    ibase1 = mod_pow(base1, mod1 - 2, mod1);
    ibase2 = mod_pow(base2, mod2 - 2, mod2);

    inv_pw[0] = {1, 1};
    for (ll i = 1; i <= N; i += 1)
    {
        pair<ll, ll> curr;
        curr.first = 1LL * inv_pw[i - 1].first * ibase1 % mod1;
        curr.second = 1LL * inv_pw[i - 1].second * ibase2 % mod2;
        inv_pw[i] = curr;
    }

    return;
}
class HashedString
{
private:
    ll len;
    vector<pair<ll, ll>> s_hash;
    string s;
public:
    HashedString(const string &str)
    {
        len = str.size();
        s_hash.push_back( {0, 0} );
        s.push_back( '$' );
        s.append( str );
        for (ll i = 1; i <= len; i += 1)
        {
            pair<ll, ll> curr;
            char ch = s[i] - 'a' + 1;
            curr.first = (s_hash[i - 1].first % mod1 + (1LL * pw[i].first * ch) % mod1) % mod1;
            curr.second = (s_hash[i - 1].second % mod2 + (1LL * pw[i].second * ch) % mod2) % mod2;
            s_hash.push_back(curr);
        }
    }
    void addChar( char ch ) {
        s.push_back( ch );
        pair<ll, ll> curr;
        ll i = s_hash.size();
        curr.first = (s_hash.back().first % mod1 + (1LL * pw[i].first * ch) % mod1) % mod1;
        curr.second = (s_hash.back().second % mod2 + (1LL * pw[i].second * ch) % mod2) % mod2;
        s_hash.push_back(curr);
    }
    pair<ll, ll> getHash(ll left, ll right)
    {
        pair<ll, ll> ans;

        ans.first = s_hash[right].first - s_hash[left - 1].first;
        if (ans.first < 0)
            ans.first += mod1;
        ans.first = ans.first * 1LL * inv_pw[left].first % mod1;

        ans.second = s_hash[right].second - s_hash[left - 1].second;
        if (ans.second < 0)
            ans.second += mod2;
        ans.second = ans.second * 1LL * inv_pw[left].second % mod2;

        return ans;
    }

    ~HashedString() = default;
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    pow_calc();
    return 0;
}