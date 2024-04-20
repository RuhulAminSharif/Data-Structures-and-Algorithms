#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
void Bubble_Sort(ll *a, ll start, ll end)
{
    for(ll i=start; i<end-1; i++){
        bool fg = true;
        for(ll j=0; j<end-i-1; j++){
            if(a[j]>a[j+1]){
                fg = false;
                swap(a[j], a[j+1]);
            }
        }
        if(fg){
            break;
        }
    }
}
int main()
{
    ll a[] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    ll size = sizeof(a)/sizeof(ll);

    Bubble_Sort(a, 0, size); //a->array, 0->start index, (size)-> size of the array

    for(ll i=0; i<size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}