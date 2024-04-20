#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
ll search(vector<int>& nums, int key)
{
    int left=0, right=nums.size()-1, mid;
    while( left <= right){
        ll mid = left + (right-left)/2;
        // Check if key is present at mid
        if(nums[mid]==key) return mid;
        // If key smaller, ignore right half
        else if(nums[mid]>key) right = mid-1;
        //// If key greater, ignore left half
        else left = mid+1;
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