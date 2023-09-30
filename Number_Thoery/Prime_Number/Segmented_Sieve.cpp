#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

const ll mx = 1e8;
vector<ll>prime;

void sieve()
{
    vector<bool>vis(mx+1,false);
    //all prime divisors of a number is before the square root of a number
    // 49 -> 7 prime divisors of 1 - 49  must be in 2 3 4 5 6 7
    for(ll i=3; i*i<=mx; i+=2){
        if(vis[i]==false){
            //i*i because there 3 -> 9 if we do i+i then 6 but it has been cut down already in time of 2
            //2*i so that we can skip the even numbers
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

void segsieve(ll left, ll right)
{
    vector<bool>vis(right-left+1, false);
    vector<ll>segprime;
    //prime[i]*prime[i] because all prime divisors are before the sqrt(n)
    for(ll i=0; prime[i]*prime[i]<=right; i++){
        ll k = left/prime[i];
        //l=20,k=20/3;k=6;k*=3;k=18 18<20 so (l%prime[i]) k++,then k=21
        if(left%prime[i]) k += 1;
        k*=prime[i];
        for(ll j=k; j<=right; j+=prime[i]){
            vis[j-left] = true;
        }
        if(k==prime[i]) vis[k-left] = false;
    }
    if(left==1) vis[0]=true;
    for(ll i=0; i<vis.size(); i++){
        if(vis[i]==false){
            segprime.push_back(i+left);
        }
    }
    for(ll i=0; i<segprime.size(); i++){
        cout << segprime[i] << " ";
    }
    return ;
}
/*
    To find all prime numbers in a range [L,R]  of small size
    (e.g. R - L + 1 equal to approx 1e7),
    and where R can be very large (e.g. 1e12).
*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    vector<ll>segprime;
    int t; cin >> t;
    while(t--){
        ll left , right; cin >> left >> right;
        segsieve(left, right);
        cout << endl;
    }
    return 0;
}