#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll power( ll b, ll p )
{
    ll ans = 1LL;
    while( p > 0 ) {
        if( p & 1 ) {
            ans *= b;
        }
        b *= b;
        p >>= 1;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cout << power(5,5) << endl;
    return 0;
}
