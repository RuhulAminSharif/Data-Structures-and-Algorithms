#include<bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int>& nums) {
    // 2 1 5 4 3 0 0
    int pos = -1, len = nums.size();
    for( int i = len-2; i >= 0 ; i -= 1 ) {
        if( nums[i] < nums[i+1] ) {
            pos = i;
            break;
        }
    }
    if( pos == -1 ) {
        int left = 0, right = len-1;
        while( left <= right ) {
            swap( nums[left], nums[right] ) ;
            left += 1;
            right -= 1;
        }
    }
    else {
        for( int i = len-1; i > pos; i -= 1 ) {
            if( nums[i] > nums[pos] ) {
                swap(nums[pos], nums[i]);
                break;
            }
        }
        int left = pos+1, right = len - 1;
        while( left <= right ) {
            swap( nums[left], nums[right] ) ;
            left += 1;
            right -= 1;
        }
    }
    return ;
}
int main()
{

}