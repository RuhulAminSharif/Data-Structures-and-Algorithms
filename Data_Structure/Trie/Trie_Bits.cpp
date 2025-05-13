#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9+7;
class Trie {
  private:
    class Node {
      public:
        vector<Node*> nextBit;
        int idx;
        Node() {
          nextBit.resize( 2, nullptr );
          idx = -1;
        }
    };
  public:
    Node * root;
    static const int B = 31;
    Trie() {
      root = new Node();
    }
    void insertNum( ll num, ll idx ) {
      Node *curr = root;
      for( int i = B - 1; i >= 0; i -= 1 ) {
        int bit = ( num >> i ) & 1;
        if( curr -> nextBit[bit] == nullptr ) {
          curr -> nextBit[bit] = new Node();
        }
        curr = curr -> nextBit[bit];
      }
      curr -> idx = idx;
      return ;
    }
    // returns maximum of val ^ x with index -> {idx, val}
    pair<int, ll> get_max( ll x ) {
      Node *curr = root;
      ll ans = 0;
      for( int i = B - 1; i >= 0; i -= 1 ) {
        int bit = ( x >> i ) & 1;
        if( curr -> nextBit[!bit] ) {
          curr = curr -> nextBit[!bit];
          ans |= ( 1 << i ) ;
        } else {
          curr =  curr -> nextBit[bit];
        }
      }
      ll idx = curr -> idx;
      return { idx, ans } ;
    }
    // returns minimum of val ^ x
    pair<int, ll> get_min( ll x ) {
      Node *curr = root;
      ll ans = 0;
      for( int i = B-1; i >= 0; i -= 1 ) {
        int bit = ( x >> i ) & 1;
        if( curr -> nextBit[bit] ) {
          curr = curr -> nextBit[bit];
        } else {
          curr =  curr -> nextBit[!bit];
          ans |= ( 1 << i ) ;
        }
      }
      ll idx = curr -> idx;
      return { idx , ans } ;
    }
};
int main()
{
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
  Trie *tr = new Trie();
  int n; cin >> n;
  vector<ll>v(n);
  for( ll i = 0; i < n; i += 1 ) {
    cin >> v[i];
    tr -> insertNum(v[i], i);
  }
  ll q; cin >> q;
  for( ll t = 1; t <= q; t += 1 ) {
    cout << "Query " << t << ": ";
    ll x; cin >> x;
    auto ans = tr -> get_max( x ) ;
    cout << ans.first + 1 << " " << ans.second << endl;
  }
  return 0;
}