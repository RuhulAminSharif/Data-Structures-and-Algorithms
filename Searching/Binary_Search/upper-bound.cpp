#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
/*
the first or the smallest index in a sorted array
where the value at that index is greater than 
to a given key i.e. key.
*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, key; cin >> n >> key;
    ll a[n]; for(ll i=0; i<n; i++) cin >> a[i];
    ll start=0, end=n-1, mid;
    while(start<=end){
        mid = start + (end-start)/2;
        if(a[mid]>key){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    cout << start << endl;
    return 0;
}