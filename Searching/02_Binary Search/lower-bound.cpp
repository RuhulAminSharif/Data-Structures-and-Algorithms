#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
/*
the first or the smallest index in a sorted array
where the value at that index is greater than or 
equal to a given key i.e. key.
*/
int lowerBound(vector<int> a, int n, int key ) 
{
    ll left=0, right=n-1, mid;
    while(left<=right){
        mid = left + (right-left)/2;
        if(a[mid]>=key){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return left;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, key; cin >> n >> key;
    vector<int>a; for(ll i=0; i<n; i++) cin >> a[i];
    
    cout << lowerBound(a,n,key) << endl;
    return 0;
}