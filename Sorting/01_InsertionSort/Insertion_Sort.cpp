#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
void insert( vector<int>& arr, int i ) {
    int j = i - 1, x = arr[i];
    while( j >= 0 && arr[j] > x ) {
        arr[j+1] = arr[j];
        j -= 1;
    }
    arr[j+1] = x;
    
}
void insertionSort(vector<int>& arr) {
    for( int i = 1; i < arr.size(); i += 1 ) {
        insert( arr, i );
    }
}
int main()
{
    vector<int> arr = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    insertionSort(arr); 
    for(int i = 0; i < arr.size(); i += 1){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}