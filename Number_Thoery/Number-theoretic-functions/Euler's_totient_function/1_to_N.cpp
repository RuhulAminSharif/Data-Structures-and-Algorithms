#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

vector<ll> phi(ll n)
{
    vector<ll>res(n+1);
    for(ll i=0; i<=n; i++){
        res[i] = i;
    }
    for(ll i=2; i<=n; i++){
        if(res[i]==i){
            for(ll j=i; j<=n; j+=i){
                res[j]=(res[j]*(i-1))/i;
            }
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n; cin >> n;
    vector<ll>ans =  phi(n);
    for(ll i=1; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}