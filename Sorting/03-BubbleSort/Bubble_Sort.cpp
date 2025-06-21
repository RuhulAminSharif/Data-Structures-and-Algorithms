#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
void bubbleSort(vector<int>& arr )
{
    for( int i = 0; i < arr.size(); i += 1 ) {
        bool fg = true;
        for( int j = 1; j < arr.size() - i; j += 1 ) {
            if( arr[j-1] > arr[j] ) {
                swap( arr[j-1], arr[j] ) ;
                fg = false;
            }
        }
        if( fg ) {
            break;
        }
    }
}
int main()
{
    vector<int> arr = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};

    bubbleSort(arr); 

    for(int i=0; i < arr.size(); i += 1 ){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}