#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
vector<ll> get_divisors( ll n )
{
    vector<ll> divs;
    for( ll i = 1LL; i * i <= n; i += 1 ) {
        if( n % i == 0 ) {
            divs.push_back(i);
            if( i != (n/i) ) {
                divs.push_back(n/i);
            }
        }
    }
    sort(divs.begin(), divs.end());
    return divs;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll n, k; cin >> n >> k;
    vector<ll> divs = get_divisors(n);
    if( k > divs.size() ) cout << -1 << endl;
    else cout << divs[k-1] << endl;
    return 0;
}

// https://codeforces.com/problemset/problem/762/A