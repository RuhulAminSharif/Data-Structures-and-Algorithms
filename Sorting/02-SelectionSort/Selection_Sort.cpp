#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
void Selection_Sort(ll *a, ll start, ll size)
{
    for(ll i=start; i<size-1; i++){
        ll min = i;
        for(ll j=i+1; j<size; j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        if(min!=i){
            swap(a[i], a[min]);
        }
    }
}
int main()
{
    ll a[] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    ll size = sizeof(a)/sizeof(ll);

    Selection_Sort(a, 0, size); //a->array, 0->start index, (size)-> size of the array

    for(ll i=0; i<size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}