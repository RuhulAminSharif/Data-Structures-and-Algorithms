#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
ll search(ll a[], ll start, ll end, ll key)
{
    while(start<=end){
        ll mid = start + (end-start)/2;
        // Check if key is present at mid
        if(a[mid]==key) return mid;
        // If key smaller, ignore right half
        else if(a[mid]>key) end = mid-1;
        //// If key greater, ignore left half
        else start = mid+1;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll a[] = {0, 1, 2, 3, 3, 5, 7, 8, 12, 12, 12, 23, 34, 66, 87};
    ll size = sizeof(a)/sizeof(ll);
    
    ll key = 87; /// Element to find 

    ll idx = search(a, 0, size-1, key); //0->start, size-1 -> end

    idx==-1? cout << "Element is not present" : cout << "Element present at index " << idx;
    cout << endl;
    return 0;
}