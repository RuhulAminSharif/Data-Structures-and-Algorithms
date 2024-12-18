#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const ll mx = 1e8;
vector<ll>primes;
vector<ll> spf(mx);
void sieve_spf() {
    for( ll i = 2; i < mx; i += 1 ) {
        spf[i] = i;
        if( i % 2 == 0 ) spf[i] = 2;
    }
    for( ll i = 3; i * i < mx; i += 2 ) {
        if( spf[i] == i ) {
            for( ll j = i * i; j < mx; j += 2 * i ) {
                spf[j] = min( spf[j], i );
            }
        }
    }
    for( ll i = 2; i < mx; i++) {
        if (spf[i] == i) {
            primes.push_back(i);
        }
    }
}
vector<ll> primeFact ( ll n ){
    vector<ll> factors;
    while( n != 1 ) {
        factors.push_back( spf[n] );
        n /= spf[n];
    }
    return factors;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve_spf();
    vector<ll> ans = primeFact(143);
    for( auto f : ans ) cout << f << " ";

    return 0;
}
