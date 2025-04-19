#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

ll getDigit(ll num, ll exp)
{
  return (num / exp) % 10;
}

// Radix Sort (non-negative integers only)
void radixSort(vector<ll> &arr)
{
  if (arr.empty())
    return;

  int maxVal = *max_element(arr.begin(), arr.end());

  // For each digit place (units, tens, hundreds, ...)
  for (ll exp = 1; maxVal / exp > 0; exp *= 10) {
    vector<vector<ll>> buckets(10); // Buckets for digits 0-9

    // Distribute elements into buckets
    for (ll num : arr) {
      ll digit = getDigit(num, exp);
      buckets[digit].push_back(num);
    }

    // Collect elements back from buckets
    int idx = 0;
    for (int i = 0; i < 10; ++i) {
      for (int num : buckets[i]) {
        arr[idx] = num;
        idx += 1;
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  ll t = 1; // cin >> t;
  for (ll test = 1; test <= t; test += 1) {
    // cout << "Case #" << test << ": ";
    ll n; cin >> n;
    vector<ll> arr(n);
    for (ll &x : arr) cin >> x;
    radixSort(arr);
    for (ll x : arr) cout << x << " ";
    cout << "\n";
  }
  return 0;
}