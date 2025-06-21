#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"

int select( vector<int>& arr, int i ) 
{
    int mnIdx = i;
    for( int idx = i + 1; idx < arr.size(); idx += 1 ) {
        if( arr[idx] < arr[mnIdx] ) {
            mnIdx = idx;
        }
    }
    return mnIdx;
}
void selectionSort( vector<int> & arr )
{
    for( int i = 0; i < arr.size(); i += 1 ) {
        int currIdx = i;
        int mnIdx = select( arr, currIdx );
        swap( arr[currIdx], arr[mnIdx] );
    }
    return ;
}
int main()
{

    vector<int> arr = {3, 7, 0, 1, 5, 8, 3, 2, 34, 66, 87, 23, 12, 12, 12};

    selectionSort(arr);

    for(int i = 0; i < arr.size(); i += 1 ){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}