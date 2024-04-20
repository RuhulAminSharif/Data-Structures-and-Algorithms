#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
void Insertion_Sort(ll *a, ll start, ll size)
{
    for(ll i= start; i<size; i++){
        ll x = a[i], j=i-1;
        while(a[j]>x && j>=0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}
int main()
{
    ll a[] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    ll size = sizeof(a)/sizeof(ll);

    Insertion_Sort(a, 1, size); //a->array, (size-1)-> end index

    for(ll i=0; i<size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}