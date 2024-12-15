#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

const ll mx = 1e8;
vector<ll>prime;

void sieve()
{
    vector<bool>vis(mx+1,true);
    //all prime divisors of a number is before the square root of a number
    // 49 -> 7 prime divisors of 1 - 49  must be in 2 3 4 5 6 7
    for(ll i=3; i*i<=mx; i+=2){
        if( vis[i] ){
            //i*i because there 3 -> 9 if we do i+i then 6 but it has been cut down already in time of 2
            //2*i so that we can skip the even numbers
            for(ll j=i*i; j<=mx; j+=2*i){
                vis[j] = false;
            }
        }
    }
    prime.push_back(2);
    for(ll i=3; i<=mx; i+=2){
        if( vis[i] ){
            prime.push_back(i);
        }
    }
    return ;
}
void primefactorization(ll n)
{
    vector<ll>primefactor;
    for(ll i=0; prime[i]*prime[i]<=n; i++){
        if(n%prime[i]==0){
            while(n%prime[i]==0){
                n/=prime[i];
                primefactor.push_back(prime[i]);
            }
        }
    }
    if(n>1) primefactor.push_back(n);
    for(ll i=0; i<primefactor.size(); i++) cout << primefactor[i] << " ";
}
// 40 = 2 2 2 5
// 19 = 19
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    primefactorization(40);
    return 0;
}