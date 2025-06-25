#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
int partition(vector<int>&arr, int low, int high) {
  int pivot = arr[ high ];
  for( int idx = low; idx < high; idx += 1 ) {
    if( arr[idx] < pivot ) {
      swap(arr[idx], arr[low]);
      low += 1;
    }
  }
  swap(arr[low], arr[high]);
  return low;
}

void quickSort(vector<int>&arr, int low, int high) {
  if( low < high ) {
    int partitionPoint = partition(arr, low, high);
    quickSort(arr, low, partitionPoint - 1);
    quickSort(arr, partitionPoint + 1, high);
  }
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  vector<int>arr = {5,4,3,2,1};
  quickSort(arr, 0, arr.size()-1);
  for(int x : arr) cout << x << " ";
  cout << endl;
  return 0;
}