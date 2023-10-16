#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
ll binary_search(vector<int>&nums, ll start, ll end, ll key)
{
    /// base case
    if(start>end) return -1;

    ll mid = start + (end-start)/2;

    // Check if key is present at mid
    if(nums[mid]==key) return mid;
    // If key smaller, ignore right half
    else if(nums[mid]>key) return binary_search(nums, start, mid-1, key);
    // If key greater, ignore left half
    else return binary_search(nums, mid+1, end, key);
}
ll search(vector<int>& nums, int key)
{
    return binary_search(nums, 0, nums.size()-1, key);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums{-1,0,3,5,9,12};
    int ans = search(nums, 9);
    cout << ans << endl;
    return 0;
}