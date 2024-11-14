#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
class segmentTree
{
  public:
    vector<pair<ll,ll>> tree;
    ll n;
    const ll inf = 1e18;
    segmentTree( vector<ll>&v , ll sz)
    {
      n = sz;
      tree.resize( 4 * n );
      build(v, 1, 1, n);
    }
    void build(vector<ll>&v, ll node, ll start, ll end)
    {
      if( start == end ) {
        tree[node] = {v[start],1};
        return ;
      }
      ll left = node << 1;
      ll right = ( node << 1 ) + 1;
      ll mid = ( start + end ) >> 1;
      build(v, left, start, mid);
      build(v, right, mid+1, end);
      if( tree[left].first < tree[right].first ) {
        tree[node] = { tree[left].first, tree[left].second };
      }
      else if( tree[right].first < tree[left].first ) {
        tree[node] = { tree[right].first, tree[right].second };
      }
      else{
        tree[node] = { tree[left].first, tree[left].second + tree[right].second };
      }
      return ;
    }
    ll query(ll node, ll start, ll end, ll ql, ll qr)
    {
      if( end < ql || start > qr ) {
        return inf;
      }
      if(ql<=start && end<=qr){
          return tree[node].first;
      }
      ll left = node << 1;
      ll right = ( node << 1 ) + 1;
      ll mid = ( start + end ) >> 1;
      ll a = query(left, start, mid, ql, qr );
      ll b = query(right, mid+1, end, ql, qr );
      return min(a,b);
    }
    ll cntMin(ll node, ll start, ll end, ll ql, ll qr, ll mn )
    {
        if( end < ql || start > qr ) {
            return 0;
        }
        if( ql <= start && end <= qr ) {
            if( tree[node].first == mn ) {
                return tree[node].second;
            }
            else return 0;
        }
        ll left = node << 1;
        ll right = ( node << 1 ) + 1;
        ll mid = ( start + end ) >> 1;
        ll cnt = 0;
        cnt += cntMin(left, start, mid, ql, qr, mn );
        cnt += cntMin(right, mid+1, end, ql, qr, mn );
        return cnt;
    }
    void update(ll node, ll start, ll end, ll index, ll value )
    {
      if( index < start || index > end ) {
        return ;
      }
      if( start == end ) {
        tree[node] = {value,1};
        return ;
      }
      ll left = node << 1;
      ll right = ( node << 1 ) + 1;
      ll mid = ( start + end ) >> 1;
      update(left, start, mid, index, value);
      update(right, mid + 1, end, index, value);
      if( tree[left].first < tree[right].first ) {
        tree[node] = { tree[left].first, tree[left].second };
      }
      else if( tree[right].first < tree[left].first ) {
        tree[node] = { tree[right].first, tree[right].second };
      }
      else{
        tree[node] = { tree[left].first, tree[left].second + tree[right].second };
      }
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
  // st.update(1, 1, n, i, val );
  // ll mn = st.query(1, 1, n, l, r );
  // ll cnt = st.cntMin(1, 1, n, l, r, mn);
}
