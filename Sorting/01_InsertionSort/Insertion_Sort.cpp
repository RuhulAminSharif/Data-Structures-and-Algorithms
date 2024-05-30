#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
void insert(int arr[], int i)
{
    int j = i-1, x = arr[i];
    while( j >= 0 && arr[j] > x ) {
        arr[j+1] = arr[j];
        j -= 1;
    }
    arr[j+1] = x;
}
void insertionSort(int arr[], int n)
{
    for( int i = 1; i < n; i += 1 ) {
        insert(arr, i);
    }
}
int main()
{
    int a[] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int size = sizeof(a)/sizeof(int);

    insertionSort(a, size); 
    for(ll i=0; i<size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}