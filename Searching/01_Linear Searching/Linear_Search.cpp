#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
ll search(ll a[], ll size, ll key)
{
    for(ll i=0; i<size; i++){
        if(a[i]==key){
            return i;
        }
    }
    return -1;
}
int main()
{
    ll a[] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    ll size = sizeof(a)/sizeof(ll);
    
    ll key = 87; /// Element to find 

    ll idx = search(a, size, key); 

    idx==-1? cout << "Element is not present" : cout << "Element present at index " << idx;
    cout << endl;
    return 0;
}