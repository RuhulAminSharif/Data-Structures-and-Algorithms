// Range query finding the sum of the values in the given range
// & update in range(Lazy Propagation) using Segment tree
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mx = 1e4+7;

ll a[mx];
struct Segtree
{
    ll prop, sum; 
}tree[4*mx]; // segment tree for sum and update in range

// initially node is root
// range beginning - start
// range finishing - end
void build(ll node, ll start, ll end) 
{
    if(start==end){
        tree[node].sum = a[start];
        return ;
    }
    ll left = 2*node; // 1 - base indexing
    ll right = 2*node+1; // 1 - base indexing
    ll mid = (start+end)/2;
    build(left, start, mid);
    build(right, mid+1, end);
    tree[node].sum = tree[left].sum+tree[right].sum;
}
// node, start, end same description as mentioned in 'build' function
// ql - query left limit, 
// qr - query right limit,
// carry - the carry value with that we will go down
ll query(ll node, ll start, ll end, ll ql, ll qr, ll carry=0)
{
    if(end<ql || qr<start){ // out of range
        return 0;
    }
    if(ql<=start && end<=qr){
        return tree[node].sum + carry*(end-start+1); // in range
    }
    
    // mixed range, need to break down more
    ll left = 2*node; // 1 - base indexing
    ll right = 2*node+1; // 1 - base indexing
    ll mid = (start+end)/2;
    ll sum = 0;
    sum += query(left, start, mid, ql, qr, carry+tree[node].prop);
    sum += query(right, mid+1, end, ql, qr, carry+tree[node].prop);

    return sum;
}
// range update
void update(ll node, ll start, ll end, ll ql, ll qr, ll value)
{
    if(qr<start || end<ql){ // out of range
        return ;
    }
    if(ql<=start && end<=qr){
        tree[node].sum += value*(end-start+1);
        tree[node].prop += value;
        return ;
    }
    ll left = 2*node; // 1 - base indexing
    ll right = 2*node+1; // 1 - base indexing
    ll mid = (start+end)/2;
    update(left, start, mid, ql, qr, value);
    update(right, mid+1, end, ql, qr, value);
    tree[node].sum = tree[left].sum+tree[right].sum+tree[node].prop*(end-start+1);
    return ;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n; cin >> n;
    for(ll i=1; i<=n; i++){ // always start from 1
        cin >> a[i];
    }
    build(1,1,n);
    return 0;
}