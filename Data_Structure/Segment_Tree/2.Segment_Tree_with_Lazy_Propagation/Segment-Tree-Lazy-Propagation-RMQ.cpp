#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
class segmentTree
{
private:
    struct Node {
        ll mn, prop;
    };

    vector<Node> tree;
    ll n;
    const ll inf = 1e18;
    void build(vector<ll> &v, ll node, ll start, ll end) {
        if (start == end) {
            tree[node].mn = v[start];
            return;
        }
        ll left = node << 1;
        ll right = (node << 1) + 1;
        ll mid = (start + end) >> 1;
        build(v, left, start, mid);
        build(v, right, mid + 1, end);
        tree[node].mn = min(tree[left].mn, tree[right].mn);
        return;
    }
    ll query(ll node, ll start, ll end, ll ql, ll qr, ll carry = 0) {
        if (end < ql || start > qr) {
            return inf;
        }
        if (ql <= start && end <= qr) {
            return tree[node].mn + carry;
        }
        ll left = node << 1;
        ll right = (node << 1) + 1;
        ll mid = (start + end) >> 1;
        ll a = query(left, start, mid, ql, qr, carry + tree[node].prop);
        ll b = query(right, mid + 1, end, ql, qr, carry + tree[node].prop);
        return min(a, b);
    }
    void update(ll node, ll start, ll end, ll ql, ll qr, ll value)
    {
        if (end < ql || start > qr) {
            return;
        }
        if (ql <= start && end <= qr) {
            tree[node].mn += value;
            tree[node].prop += value;
            return;
        }
        ll left = node << 1;
        ll right = (node << 1) + 1;
        ll mid = (start + end) >> 1;
        update(left, start, mid, ql, qr, value);
        update(right, mid + 1, end, ql, qr, value);
        tree[node].mn = min(tree[left].mn, tree[right].mn) + tree[node].prop;
        return;
    }

public:
    segmentTree(vector<ll> &v, ll sz) {
        n = sz;
        tree.resize(4 * n);
        build(v, 1, 1, n);
    }
    ll rangeQuery(ll ql, ll qr) {
        return query(1, 1, n, ql, qr);
    }
    void rangeUpdate(ll ql, ll qr, ll value){
        update(1, 1, n, ql, qr, value);
        return;
    }
};
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n + 1);
    for (ll i = 1; i <= n; i += 1)
    {
        cin >> v[i];
    }
    segmentTree st(v, n);
    // st.rangeUpdate(l, r, x);
    // st.rangeQuery(l, r);
}
