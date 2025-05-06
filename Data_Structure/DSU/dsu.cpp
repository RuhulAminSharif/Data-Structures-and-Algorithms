#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

class DSU
{
private:
  vector<ll> _rank, _size, _parent;
public:
  DSU(ll n) {
    _rank.resize( n + 1, 0 );
    _size.resize( n + 1, 1 );
    _parent.resize( n + 1 );
    for( ll i = 0; i <= n; i += 1 ) {
      _parent[i] = i;
    }
  }
  ll findParent( ll node ) {
    if( _parent[node] == node ) {
      return node;
    }
    return _parent[node] = findParent( _parent[node] );
  }
  void unionByRank( ll u, ll v ) {
    ll pu = findParent(u);
    ll pv = findParent(v);
    if( pu == pv ) return ;
    if( _rank[ pu ] > _rank[ pv ] ) {
      _parent[ pv ] = pu;
    } else if( _rank[ pv ] > _rank[ pu ] ) {
      _parent[ pu ] = pv;
    } else {
      _parent[ pu ] = pv;
      _rank[ pv ] += 1;
    }
    return ;
  }
  void unionBySize( ll u, ll v ) {
    ll pu = findParent(u);
    ll pv = findParent(v);
    if( pu == pv ) return ;
    if( _size[ pu ] > _size[ pv ] ) {
      _parent[ pv ] = pu;
      _size[ pu ] += _size[ pv ];
    } else if( _size[ pv ] > _size[ pu ] ) {
      _parent[ pu ] = pv;
      _size[ pv ] += _size[ pu ];
    } else {
      _parent[ pu ] = pv;
      _size[ pv ] += _size[ pu ];
    }
    return ;
  }
  ~DSU() = default;
};
int main() {
  fast_io();
  ll n, q; cin >> n >> q;
  DSU ds( n );
  while( q-- ) {
    ll t, u, v; cin >> t >> u >> v;
    if( t ) {
      // checking whether u and v are in same components
      cout << ( ds.findParent(u) == ds.findParent(v) ) << endl;
    } else {
      // add node u to v in DSU
      ds.unionByRank( u, v );
    }
  }
  return 0;
}