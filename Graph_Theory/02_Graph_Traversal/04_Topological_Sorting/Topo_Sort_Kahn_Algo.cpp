#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define endl "\n"

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  ll nodes, edges; cin >> nodes >> edges;
  vector<vector<ll>> adj( nodes + 1 );
  vector<ll> inDegree( nodes + 1, 0 ); 
  for( ll i = 1; i <= edges; i += 1 ) {
    ll u, v; cin >> u >> v;
    adj[u].push_back( v );
    inDegree[ v ] += 1;
  }
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  for( ll i = 1; i <= nodes; i += 1 ) {
    if( inDegree[i] == 0 ) {
      pq.push( i );
    }
  }
  vector<ll> topo;
  while( pq.size() > 0 ) {
    ll u = pq.top();
    pq.pop();
    topo.push_back( u );
    for( ll v : adj[u] ) {
      inDegree[v] -= 1;
      if( inDegree[v] == 0 ) {
        pq.push( v );
      }
    }
  }
  if( topo.size() != nodes ) {
    // not possible 
    cout << -1 << endl;
  } else {
    for( auto node : topo ) {
      cout << node << " ";
    }
    cout << endl;
  }
  return 0;
}
