#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const ll mx = 1e6+5;
vector<ll>prime;
vector<pair<ll,ll>>factorcnt;
void sieve()
{
    vector<bool>vis(mx+1,false);
    for(ll i=3; i*i<=mx; i+=2){
        if(vis[i]==false){
            for(ll j=i*i; j<=mx; j+=2*i){
                vis[j]=true;
            }
        }
    }
    prime.push_back(2);
    for(ll i=3; i<=mx; i+=2){
        if(vis[i]==false){
            prime.push_back(i);
        }
    }
    return ;
}
ll SOD(ll n)
{
    for(ll i=0; prime[i]*prime[i]<=n; i++){
        ll cnt=0;
        if(n%prime[i]==0){
            while(n%prime[i]==0){
                n/=prime[i];
                cnt += 1;
            }
        }
        if(cnt) factorcnt.push_back({prime[i],cnt});
    }
    if(n>1) factorcnt.push_back({n,1});

    ll sod = 1;
    for(ll i=0; i<factorcnt.size(); i++){
        sod *= ((pow(factorcnt[i].first,factorcnt[i].second+1))-1)/(factorcnt[i].first-1);
    }
    return sod;
}
//do prime factorization : n = (p1^a1) * (p2^a2) * (p3^a3) *.....* (pk^ak)
//SOD ( n ) = ( ( p1^(a1+1) - 1 )/(p1-1) )*( ( p2^(a2+1) - 1 )/(p2-1) )* ........* ( ( pk^(ak+1) - 1 )/(pk-1) )
//Time Complexity : O ( sqrt(n) )
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    ll n; cin >> n;
    cout << SOD(n) << endl;
    return 0;
}