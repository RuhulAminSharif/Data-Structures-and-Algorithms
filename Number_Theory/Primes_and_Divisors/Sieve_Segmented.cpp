#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mx = 1e7+9;
vector<int> primes;
void sieve()
{
  vector<bool> vis(mx,true);
  for( ll i = 3; i * i < mx; i += 1 ) {
    if( vis[i] ) {
      for( ll j = i * i; j < mx; j += 2 * i ) {
        vis[j] = false;
      }
    }
  }
  primes.push_back( 2 ) ;
  for( ll i = 3; i < mx; i += 2 ) {
    if( vis[i] ) {
      primes.push_back( i );
    }
  }
  return ;
}
void segmented_sieve( ll left, ll right )
{
  vector<bool> vis( right - left + 1 , true ) ;
  for( ll i = 0; primes[i] * primes[i] <= right; i += 1 ) {
    ll k = (left/primes[i]) * primes[i];
    if( k < left ) k += primes[i];
    for( ll j = k; j <= right; j += primes[i] ) {
      vis[j-left] = false;
    }
    if( k == primes[i] ) vis[k-left] = true;
  }
  if( left == 1 ) vis[0] = false;
  vector<ll> segprimes;
  for(ll i=0; i<vis.size(); i++){
    if( vis[i] ){
      segprimes.push_back(i+left);
    }
  }
  for(ll i=0; i < segprimes.size(); i++){
    cout << segprimes[i] << " ";
  }
  return ;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  sieve();
  ll t; cin >> t;
  while( t-- ) {
    ll l, r; cin >> l >> r;
    segmented_sieve(l,r);
    cout << endl;
  }
}