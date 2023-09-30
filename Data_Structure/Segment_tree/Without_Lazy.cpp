#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mx = 1e5+7;

ll a[mx];
ll tree[4*mx]; // segment tree for sum

// initially node is root
// range beginning - start
// range finishing - end
void build(ll node, ll start, ll end) 
{
    if(start==end){
        tree[node] = a[start];
        return ;
    }
    ll left = 2*node; // 1 - base indexing
    ll right = 2*node+1; // 1 - base indexing
    ll mid = (start+end)/2;
    build(left, start, mid);
    build(right, mid+1, end);
    tree[node] = tree[left]+tree[right];
}
// node, start, end same description as mentioned in 'build' function
// ql - query left limit, 
// qr - query right limit
ll query(ll node, ll start, ll end, ll ql, ll qr)
{
    if(end<ql || qr<start){ // out of range
        return 0;
    }
    if(ql<=start && end<=qr){
        return tree[node]; // in range
    }
    
    // mixed range, need to break down more
    ll left = 2*node; // 1 - base indexing
    ll right = 2*node+1; // 1 - base indexing
    ll mid = (start+end)/2;
    ll sum = 0;
    sum += query(left, start, mid, ql, qr);
    sum += query(right, mid+1, end, ql, qr);

    return sum;
}
// single index update
void update(ll node, ll start, ll end, ll index, ll value)
{
    if(index<start || end<index){ // out of range
        return ;
    }
    if(index<=start && end<=index){
        tree[node] = value;
        return ;
    }
    ll left = 2*node; // 1 - base indexing
    ll right = 2*node+1; // 1 - base indexing
    ll mid = (start+end)/2;
    update(left, start, mid, index, value);
    update(right, mid+1, end, index, value);
    tree[node] = tree[left]+tree[right];
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