#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
ll search(vector<int>& nums, int key)
{
    int start=0, end=nums.size()-1, mid;
    while(start<=end){
        ll mid = start + (end-start)/2;
        // Check if key is present at mid
        if(nums[mid]==key) return mid;
        // If key smaller, ignore right half
        else if(nums[mid]>key) end = mid-1;
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
    vector<int>nums{-1,0,3,5,9,12};
    int ans = search(nums, 9);
    cout << ans << endl;
    return 0;
}