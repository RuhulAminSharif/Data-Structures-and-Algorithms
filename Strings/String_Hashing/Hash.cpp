#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define inf 1e18
long long mod_pow(long long b, long long p, const int mod)
{
    long long r = 1 % mod;
    b %= mod;
    if( b < 0 ) b += mod;
    while(p){
        if(p&1) {
            r = (long long) (r * b) % mod;
        }
        b = (long long) (b * b) % mod;
        p >>= 1;
    }
    return r;
}
const int mod1 = 1e9+7, mod2 = 1e9+9;
const int base1 = 159, base2 = 277;
int ibase1, ibase2;
const int N = 1e7+9;
vector<pair<int,int>> pw(N), inv_pw(N);
void pow_calc()
{
    pw[0] = {1, 1};
    for( int i = 1; i < N; i += 1 ) {
        pw[i].first = 1LL * pw[i-1].first * base1 % mod1;
        pw[i].second = 1LL * pw[i-1].second * base2 % mod2;
    }
    ibase1 = mod_pow(base1, mod1-2, mod1);
    ibase2 = mod_pow(base2, mod2-2, mod2);
    inv_pw[0] = {1,1};
    for( int i = 1; i < N; i += 1 ) {
        inv_pw[i].first = 1LL * inv_pw[i-1].first * ibase1 % mod1;
        inv_pw[i].second = 1LL * inv_pw[i-1].second * ibase2 % mod2;
    }
}
struct HashedString {
    int len;
    vector<pair<int,int>> s_hash;
    Hashing() {}
    HashedString(const string& s ) {
        len = s.size();
        s_hash.resize(len+1);
        for( int i = 0; i < len; i += 1 ) {
            pair<int,int> p;
            p.first = ( s_hash[i].first + 1LL * pw[i].first * s[i] % mod1 ) % mod1;
            p.second = ( s_hash[i].second + 1LL * pw[i].second * s[i] % mod2 ) % mod2;
            s_hash[i+1] = p;
        }
    }
    pair<int,int> getHash( int left, int right ) {
        assert( 1 <= left && left <= right && right <= len );
        pair<int,int> ans;
        ans.first = ( s_hash[right].first - s_hash[left-1].first + mod1) * 1LL * inv_pw[left-1].first % mod1;
        ans.second = ( s_hash[right].second - s_hash[left-1].second + mod2) * 1LL * inv_pw[left-1].second % mod2;
    //    if( ans.first < 0 ) ans.first += mod1;
    //    if( ans.second < 0 ) ans.second += mod2;
        return ans;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pow_calc();
    string s = "abab";
    HashedString hs(s);
    if( hs.getHash(1,2) == hs.getHash(3,4) ) {
        cout << "the substring consisting first and second character equal to substring consisting of third and fourth character" << endl;
    }
    else {
        cout << "not equal" << endl;
    }
    return 0;
}
