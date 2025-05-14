#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

vector<ll> createlps( string& pattern )
{
  ll len = pattern.size();
  vector<ll> lps ( len + 1 , 0);
  lps[0] = -1;
  for( ll idx = 1; idx <= len; idx += 1 ) {
    ll k = lps[idx-1];
    while( k >= 0 && pattern[k] != pattern[idx-1] ) {
      k = lps[k];
    }
    lps[idx] = k + 1;
  }
  return lps;
}
vector<ll> kmp(string& text, string& pattern){
  vector<ll> lps = createlps(pattern);
  vector<ll> occur;
  ll idxP = 0, idxT = 0;
  while( idxT < text.size() ) {
    if( text[idxT] == pattern[idxP] ) {
      idxP += 1;
      idxT += 1;
    } else {
      if( idxP != 0 ) {
        idxP = lps[idxP];
      } else {
        idxT += 1;
      }
    }
    if( idxP == pattern.size() ) {
      occur.push_back( idxT - pattern.size() + 1 );
      idxP = lps[idxP];
    }
  }
  return occur;
}
vector<ll> mergedKMP(string& text, string& pattern) {
  string tt = pattern + '#' + text;
  vector<ll> lps = createlps(tt);
  vector<ll> occur;
  for( ll i = pattern.size() + 1; i < lps.size(); i += 1 ) {
    if( lps[i] == pattern.size() ) {
      occur.push_back( i - 2 * pattern.size() );
    }
  }
  return occur;
}
int main() {
  string text = "AbcabcABC";
  string pattern = "abc";

  vector<ll> matches = kmp(text, pattern);
  vector<ll> matchesC = mergedKMP(text, pattern);
  cout << "X";
  for (auto &idx : matches) {
    cout << "Pattern found at 1-based index: " << idx << endl;
  }
  for (auto &idx : matchesC) {
    cout << "Pattern found at 1-based index: " << idx << endl;
  }
  return 0;
}
