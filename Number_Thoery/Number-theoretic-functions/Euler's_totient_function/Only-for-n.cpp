#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

const ll mx = 1e8;
vector<bool>vis(mx+1);
vector<ll>prime;
set<ll>prime1;

void sieve()
{
    vis[0]=vis[1] = true;
    //all prime divisors of a number is before the square root of a number
    // 49 -> 7 prime divisors of 1 - 49  must be in 2 3 4 5 6 7
    for(ll i=3; i*i<=mx;i+=2){
        if(vis[i]==false){
            //i*i because there 3 -> 9 if we do i+i then 6 but it has been cut down already in time of 2
            //2*i so that we can skip the even numbers
            for(ll j=i*i; j<=mx; j+=2*i){
                vis[j]=true;
            }
        }
    }
    prime.push_back(2);
    prime1.insert(2);
    for(ll i=3; i<=mx; i+=2){
        if(vis[i]==false){
            prime.push_back(i);
            prime1.insert(i);
        }
    }
}

ll phi(ll n)
{
    ll res = n;
    for(ll i=0; prime[i]*prime[i]<=n; i++){
        if(n%prime[i]==0){
            while(n%prime[i]==0){
                n /= prime[i];
            }
            res -= res/prime[i];
        }
    }
    if(n>1){
        res -= res/n;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    ll q; cin >> q;
    while(q--){
        ll n; cin >> n;
        cout << phi(n) << endl;
    }
    return 0;
}