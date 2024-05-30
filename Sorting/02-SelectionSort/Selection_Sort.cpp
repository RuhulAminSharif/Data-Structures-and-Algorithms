#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
int select(int arr[], int i, int n)
{
    int mnIdx = i, mn = arr[i];
    for( int idx = i+1; idx < n; idx += 1 ) {
        if( arr[idx] < mn ) {
            mn = arr[idx];
            mnIdx = idx;
        }
    }
    return mnIdx;
}
     
void selectionSort(int arr[], int n)
{
    for( int i = 0; i < n; i += 1 ) {
        int idx = select( arr, i, n) ;
        swap(arr[idx], arr[i]);
    }
}
int main()
{
    int a[] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int size = sizeof(a)/sizeof(int);

    selectionSort(a, size);

    for(ll i=0; i<size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}