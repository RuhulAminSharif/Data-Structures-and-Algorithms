#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int N = 1e7+9;
int spf[N];
vector<int> primes;
void sieve_linear( )
{
    for( int i = 2; i < N; i += 1 ) {
        if( spf[i] == 0 ) {
            spf[i] = i;
            primes.push_back(i);
        }
        for( int j = 0; j < primes.size() && i * primes[j] < N && primes[j] <= spf[i] ; j += 1 ) {
            spf[ i * primes[j] ] = primes[j];
        }
    }
    return ;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve_linear();
    for( auto it : primes ) {
        cout << it << " ";
    }
    return 0;
}
