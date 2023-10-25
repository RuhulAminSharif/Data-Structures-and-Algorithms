// KMP for substring search 
// complexity O(n+m)
// where n is the length of text
// and m is the length of pattern
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mx = 2e5+5; // size for pattern string
ll lps[mx];
void createlps(string pattern)
{
    ll index=0; // for lps array track
    for(ll i=1; i<pattern.size();){
        if(pattern[i]==pattern[index]){
            lps[i++] = ++index;
        }else{
            if(index!=0){
                index = lps[index-1];
            }else{
                lps[i++] = index;
            }
        }
    }
}
bool kmp(string text, string pattern)
{
    // index -- > pattern, i -- > text
    ll index=0, i=0;
    bool fg = false;
    while(i<text.size()){
        if(pattern[index]==text[i]){
            ++i, ++index;
        }else{
            if(index!=0){
                index = lps[index-1];
            }else{
                ++i;
            }
        }
        if(index==pattern.size()-1){
            // cout << i-pattern.size()+1 << endl; // from where the substring is found, starting index
            index = lps[index-1];//for all occurances
            fg = true;
            // break; if we don't require all occurances
        }
    }
    if(fg) return true;
    else return false;
} 
int main()
{
    string text, pattern;
    cin  >> text >> pattern;
    createlps(pattern);
    for(int i=0; i<pattern.size(); i++){
        cout << lps[i] << " ";
    }
    cout << endl;
    if(kmp(text,pattern)){
        cout << "Found" << endl;
    }else{
        cout << "Not Found" << endl;
    }
}
