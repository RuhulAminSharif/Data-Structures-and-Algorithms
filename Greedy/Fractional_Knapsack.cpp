#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
  int n = wt.size();
  
  vector<pair<double, int>> ratio(n);
  for (int i = 0; i < n; i += 1) {
      ratio[i] = { (double)val[i] / wt[i], i };
  }
  
  sort(ratio.rbegin(), ratio.rend());
  
  double totSum = 0.0;
  for (int i = 0; i < n && capacity > 0; i += 1) {
      int idx = ratio[i].second;
      
      int takeWt = min(capacity, wt[idx]);
      totSum += takeWt * ratio[i].first;
      capacity -= takeWt;
  }
  
  return totSum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, capacity; cin >> n >> capacity;
    vector<int> val(n), wt(n);
    for( int i=0; i<n; i++) cin >> val[i];
    for( int i=0; i<n; i++) cin >> wt[i];
    cout << fractionalKnapsack(val, wt, capacity) << endl;
}