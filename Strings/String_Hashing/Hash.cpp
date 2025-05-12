#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
class HashedString
{
private:
    const int mod1 = 1e9+7, mod2 = 1e9+9;
    const int base1 = 37, base2 = 53;
    int ibase1, ibase2;
    ll len;
    vector<pair<ll,ll>> s_hash;
    vector<pair<ll,ll>> pow, inv_pow;
public:
    HashedString(const string& str) {
        len = str.size();
        pow_calc( len );
        s_hash.resize( len + 1 );
        s_hash[0] = { 0, 0};
        string s = '$' + str; // converted into 1 - based string
        for( ll i = 1; i <= len; i += 1 ) {
            pair<ll,ll> curr;
            char ch = s[i] - 'a' + 1;
            curr.first = ( s_hash[i-1].first % mod1 + ( 1LL * pow[i].first * ch ) % mod1 ) % mod1;
            curr.second = ( s_hash[i-1].second % mod2 + ( 1LL * pow[i].second * ch ) % mod2 ) % mod2;
            s_hash[i] = curr;
        }

    }
    pair<ll,ll> getHash( ll left, ll right ) { // 1 - based index
        pair<ll,ll> ans;

        ans.first = s_hash[right].first - s_hash[left-1].first;
        if( ans.first < 0 ) ans.first += mod1;
        ans.first = ans.first * 1LL * inv_pow[left].first % mod1;

        ans.second = s_hash[right].second - s_hash[left-1].second;
        if( ans.second < 0 ) ans.second += mod2;
        ans.second = ans.second * 1LL * inv_pow[left].second % mod2;

        return ans;
    }
    void pow_calc(ll n) {
        pow.resize( n + 1 );
        inv_pow.resize( n + 1 );
        pow[0] = { 1LL, 1LL };
        for( ll i = 1; i <= n; i += 1 ) {
            pair<ll,ll> curr;
            curr.first = 1LL * pow[i-1].first * base1 % mod1;
            curr.second = 1LL * pow[i-1].second * base2 % mod2;
            pow[i] = curr;
        }

        ibase1 = mod_pow(base1, mod1-2, mod1);
        ibase2 = mod_pow(base2, mod2-2, mod2);

        inv_pow[0] = {1,1};
        for( ll i = 1; i <= n; i += 1 ) {
            pair<ll,ll> curr;
            curr.first = 1LL * inv_pow[i-1].first * ibase1 % mod1;
            curr.second = 1LL * inv_pow[i-1].second * ibase2 % mod2;
            inv_pow[i] = curr;
        }

        return ;
    }
    long long mod_pow(long long b, long long p, const int mod)
    {
        long long r = 1 % mod;
        b %= mod;
        if( b < 0 ) b += mod;
        while(p){
            if( p & 1 ) {
                r = (long long) (r * b) % mod;
            }
            b = (long long) (b * b) % mod;
            p >>= 1;
        }
        return r;
    }
    ~HashedString() = default;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    while( cin >> n ) {
        string text, pattern;
        cin >> pattern >> text;
        HashedString hp(pattern);
        auto hpv = hp.getHash( 1, pattern.size() );
        HashedString ht( text );
        ll ans = 0;
        for( ll i = 1; i + n - 1 <= text.size(); i += 1 ) {
            if( ht.getHash(i, i + n - 1) == hpv ) {
                cout << i - 1  << endl;
            }
        }
        cout << endl;
    }

    return 0;
}

// https://www.spoj.com/problems/NHAY/