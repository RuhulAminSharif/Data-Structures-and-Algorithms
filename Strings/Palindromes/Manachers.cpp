#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9+7;
class Manacher {
private:
    vector<ll> p;
    string s;
public:
    Manacher(string &str )
    {
        s += '#';
        for( ll i = 0; i < str.size(); i += 1 ) {
            s += (str[i]);
            s += '#';
        }
        p.resize(s.size(),1);
        ll l = 1, r = 1;
        for( ll i = 0; i < s.size(); i += 1 ){
            p[i] = max( 0LL, min( (r-i), p[l+(r-i)]) );
            while( ( i + p[i] ) < s.size() && ( i - p[i] ) >= 0 && s[i-p[i]] == s[ i + p[i] ] ) {
                p[i] += 1;
            }
            if( (i+p[i]) > r ) {
                r = i + p[i] - 1;
                l = i - p[i] + 1;
            }
        }
//        for( auto it : p ) {
//            cout << it << " ";
//        }
    }
    ll getLongest( ll cen, bool odd )
    {
        ll pos = 2 * cen + 1 + (!odd);
        return p[pos] - 1;
    }
    bool isPalin( ll l, ll r )
    {
        if( ( r - l + 1 ) <= getLongest( (l+r)/2, l%2==r%2 ) ) {
            return true;
        }
        else {
            return false;
        }
    }
};
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string s;
    cin >> s;
    Manacher * man = new Manacher(s);
    string ans = "";
    ll mx = 0, idx = -1;
    bool odd = true;
    for( ll i = 0; i < s.size(); i += 1 ) {
        ll oddLen = man -> getLongest(i,true);
        ll evenLen = man -> getLongest(i,false);
        if( oddLen > evenLen ) {
            if( oddLen > mx ) {
                mx = oddLen;
                idx = i;
                odd = true;
            }
        }
        else {
            if( evenLen > mx ) {
                mx = evenLen;
                idx = i;
                odd = false;
            }
        }
    }
    if( odd ) {
        for( ll i = idx - (mx/2); i < idx + (mx/2) + 1; i += 1 ) {
            ans += s[i];
        }
    }
    else {
        for( ll i = idx - (mx/2) + 1; i < idx + (mx/2) + 1; i += 1 ) {
            ans += s[i];
        }
    }
    cout << ans << endl;
    return 0;
}

// https://cses.fi/problemset/task/1111