#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
void merge(vector<int>& arr, int l, int m, int r)
{
    int leftLen = m - l + 1;
    int rightLen = r - m ;
    vector<int> leftArr(leftLen), rightArr(rightLen);
    for( int i = 0; i < leftLen; i += 1 ) {
        leftArr[i] = arr[ l + i ];
    }
    for( int i = 0; i < rightLen; i += 1 ) {
        rightArr[i] = arr[ m + 1 + i ];
    }
    int left = 0, right = 0;
    while( left < leftLen && right < rightLen ) {
        if( leftArr[left] <= rightArr[right] ) {
            arr[l++] = leftArr[left++];
        }
        else {
            arr[l++] = rightArr[right++];
        }
    }
    while( left < leftLen ) {
        arr[l++] = leftArr[left++];
    }
    while( right < rightLen ) {
        arr[l++] = rightArr[right++];
    }
    return ;
}
void mergeSort(vector<int>& arr, int l, int r) {
    if( l >= r ) return ;
    int mid = ( l + r ) / 2;
    mergeSort( arr, l, mid );
    mergeSort( arr, mid + 1, r );
    merge( arr, l, mid, r );
    return ;
}
int main()
{
    vector<int> arr = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    mergeSort(arr, 0, arr.size()-1);
    for(int i = 0; i < arr.size(); i += 1 ) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}