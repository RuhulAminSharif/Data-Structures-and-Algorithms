#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
vector<ll> createlps( string pattern )
{
    ll len = pattern.size();
    vector<ll>lps(len, 0);
    ll idxLps = 0, idx = 1;
    while( idx < len ) {
        if( pattern[idxLps] == pattern[idx] ) {
            lps[idx] = idxLps + 1;
            idxLps += 1;
            idx += 1;
        }
        else {
            if( idxLps != 0 ) {
                idxLps = lps[idxLps-1];
            }
            else {
                lps[idx] = 0;
                idx += 1;
            }
        }
    }
    return lps;
}
bool kmp(string text, string pattern){
    
    vector<ll> lps = createlps(pattern);
    
    ll idxP = 0, idxT = 0;
    bool fg = false;
    
    while( idxT < text.size() ) {
        if( pattern[idxP] == text[idxT] ) {
            idxP += 1;
            idxT += 1;
        }
        else {
            if( idxP != 0 ) {
                idxP = lps[idxP-1];
            }
            else {
                idxT += 1;
            }
        }
        if( idxP == pattern.size() ) {
            // +1 if we need to return 1-base indexing matching starting position
            cout << idxT - pattern.size() + 1 << endl; // from where the substring is found, starting index
            idxP = lps[idxP-1]; //for all occurances
            fg = true;
            break; // if we don't require all occurance
        }
    }
    if( fg ) return true;
    else return false;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string text, pattern;    cin  >> text >> pattern;
    if( kmp( text, pattern ) ) {
        cout << "Found" << endl;
    }
    else {  
        cout << "Not Found" << endl;
    }
}

