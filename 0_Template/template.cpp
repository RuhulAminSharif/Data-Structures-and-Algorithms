#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl "\n"

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
    #define debug(x)
#endif

#define pi acos(-1)

void _print(int x) { cerr << x; }
void _print(ll x) { cerr << x; }
void _print(ull x) { cerr << x; }
void _print(double x) { cerr << x; }
void _print(ld x) { cerr << x; }
void _print(bool x) { cerr << (x ? "true" : "false"); }
void _print(char x) { cerr << '\'' << x << '\''; }
void _print(string x) { cerr << '\"' << x << '\"'; }

template<class T> void _print(vector<T> v);
template<class T> void _print(set<T> v);
template<class T> void _print(multiset<T> v);
template<class T> void _print(unordered_set<T> v);
template<class T> void _print(deque<T> v);
template<class T> void _print(stack<T> v);
template<class T> void _print(queue<T> v);
template<class T, class V> void _print(map<T, V> v);
template<class T, class V> void _print(unordered_map<T, V> v);
template<class T, class V> void _print(pair<T, V> p);

template<class T> void _print(vector<T> v) { cerr << "[ "; for (T i : v) _print(i), cerr << " "; cerr << "]"; }
template<class T> void _print(set<T> v) { cerr << "{ "; for (T i : v) _print(i), cerr << " "; cerr << "}"; }
template<class T> void _print(multiset<T> v) { cerr << "{ "; for (T i : v) _print(i), cerr << " "; cerr << "}"; }
template<class T> void _print(unordered_set<T> v) { cerr << "{ "; for (T i : v) _print(i), cerr << " "; cerr << "}"; }
template<class T> void _print(deque<T> v) { cerr << "[ "; for (T i : v) _print(i), cerr << " "; cerr << "]"; }
template<class T> void _print(stack<T> s) { cerr << "[ "; while (!s.empty()) _print(s.top()), cerr << " ", s.pop(); cerr << "]"; }
template<class T> void _print(queue<T> q) { cerr << "[ "; while (!q.empty()) _print(q.front()), cerr << " ", q.pop(); cerr << "]"; }
template<class T, class V> void _print(map<T, V> v) { cerr << "{ "; for (auto i : v) _print(i), cerr << " "; cerr << "}"; }
template<class T, class V> void _print(unordered_map<T, V> v) { cerr << "{ "; for (auto i : v) _print(i), cerr << " "; cerr << "}"; }
template<class T, class V> void _print(pair<T, V> p) { cerr << "("; _print(p.first); cerr << ", "; _print(p.second); cerr << ")"; }

const ll mod = 1e9 + 7;
const ll mod1 = 1e9 + 11;
const int inf = 1e9;
const ll linf = 1e18;


int main() {
    fast_io();
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    ll t = 1; cin >> t;
    for (ll test = 1; test <= t; test += 1 ) {
        // cout << "Case #" << test << ": ";
        ;
    }
    return 0;
}
