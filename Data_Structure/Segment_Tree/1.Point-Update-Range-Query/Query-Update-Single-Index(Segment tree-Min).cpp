#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
class segmentTree
{
  public:
    vector<ll> tree;
    ll n;
    const ll inf = 1e18;
    segmentTree( vector<ll>&v , ll sz)
    {
      n = sz;
      tree.resize( 4 * n + 1, 0);
      build(v, 1, 1, n);
    }
    void build(vector<ll>&v, ll node, ll start, ll end)
    {
      if( start == end ) {
        tree[node] = v[start];
        return ;
      }
      ll left = node << 1;
      ll right = ( node << 1 ) + 1;
      ll mid = ( start + end ) >> 1;
      build(v, left, start, mid);
      build(v, right, mid+1, end);
      tree[node] = min(tree[left], tree[right]);
      return ;
    }
    ll query(ll node, ll start, ll end, ll ql, ll qr)
    {
      if( end < ql || start > qr ) {
        return inf;
      }
      if(ql<=start && end<=qr){
          return tree[node];
      }
      ll left = node << 1;
      ll right = ( node << 1 ) + 1;
      ll mid = ( start + end ) >> 1;
      ll a = query(left, start, mid, ql, qr );
      ll b = query(right, mid+1, end, ql, qr );
      return min(a,b);
    }
    void update(ll node, ll start, ll end, ll index, ll value )
    {
      if( index < start || index > end ) {
        return ;
      }
      if( index <= start && end <= index ) {
        tree[node] = value;
        return ;
      }
      ll left = node << 1;
      ll right = ( node << 1 ) + 1;
      ll mid = ( start + end ) >> 1;
      update(left, start, mid, index, value);
      update(right, mid + 1, end, index, value);
      tree[node] = min(tree[left], tree[right]);
      return ;
    }
};
int main()
{
  ll n, m; cin >> n >> m;
  vector<ll> v(n+1);
  for( ll i = 1; i <= n; i += 1 ) {
    cin >> v[i];
  }
  segmentTree st(v, n);
  //  st.update(1, 1, n, i, val );
  // st.query(1, 1, n, l, r );
  return 0;
}
