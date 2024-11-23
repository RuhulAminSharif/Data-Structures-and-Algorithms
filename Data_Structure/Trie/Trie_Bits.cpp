#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9+7;
class Trie {
private:
    class Node {
    public:
        Node *nextBit[2];
        Node() {
            nextBit[0] = nextBit[1] = nullptr;
        }
    };
public:
    Node * root;
    static const int B = 31;
    Trie() {
        root = new Node();
    }
    void insertNum( ll num ) {
        Node *curr = root;
        for( int i = B-1; i >= 0; i -= 1 ) {
            int bit = ( num >> i ) & 1;
            if( curr -> nextBit[bit] == nullptr ) {
                curr -> nextBit[bit] = new Node();
            }
            curr = curr -> nextBit[bit];
        }
        return ;
    }
    // returns maximum of val ^ x
    ll get_max( ll x ) {
        Node *curr = root;
        ll ans = 0;
        for( int i = B-1; i >= 0; i -= 1 ) {
            int bit = ( x >> i ) & 1;
            if( curr -> nextBit[!bit] ) {
                curr = curr -> nextBit[!bit];
                ans |= ( 1 << i ) ;
            }
            else {
                curr =  curr -> nextBit[bit];
            }
        }
        return ans;
    }
    // returns minimum of val ^ x
    ll get_min( ll x ) {
        Node *curr = root;
        ll ans = 0;
        for( int i = B-1; i >= 0; i -= 1 ) {
            int bit = ( x >> i ) & 1;
            if( curr -> nextBit[bit] ) {
                curr = curr -> nextBit[bit];
            }
            else {
                curr =  curr -> nextBit[!bit];
                ans |= ( 1 << i ) ;
            }
        }
        return ans;
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
        tr -> insertNum(v[i]);
    }
    ll ans = 0;
    for( ll i = 0; i < n; i += 1 ) {
        ans = max( ans, tr -> get_max(v[i]) );
    }
    cout << ans << endl;
    return 0;
}