#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
void merge(int arr[], int l, int m, int r)
{
    int leftLen = m - l + 1;
    int rightLen = r - m ;
    int leftArr[leftLen];
    int rightArr[rightLen];
    for( int i = 0; i < leftLen; i += 1 ) {
        leftArr[i] = arr[l+i];
    }
    for( int i = 0; i < rightLen; i += 1 ) {
        rightArr[i] = arr[m+1+i];
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
void mergeSort(int arr[], int l, int r)
{
    if( l >= r ) return ;
    int mid = ( l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
    return ;
}
int main()
{
    int a[] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int size = sizeof(a)/sizeof(int);

    mergeSort(a, 0, size-1);

    for(ll i=0; i<size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}