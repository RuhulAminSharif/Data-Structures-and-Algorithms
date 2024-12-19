#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll gcd( ll a, ll b )
{
    return b ? gcd(b,a%b) : a;
}
ll lcm( ll a, ll b )
{
    return 1LL * a * b / gcd(a,b);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1; cin >> t;
    while( t-- ) {
        ll a, b; cin >> a >> b;
        cout << lcm(a,b) << " " << gcd(a,b) << endl;
    }
    return 0;
}
// https://www.hackerrank.com/contests/smart-interviews/challenges/si-lcm-and-hcf 