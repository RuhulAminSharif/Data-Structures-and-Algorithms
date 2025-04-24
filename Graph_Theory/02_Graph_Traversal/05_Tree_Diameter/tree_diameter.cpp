#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl "\n"

pair<ll, ll> furthestCalc(ll src, ll nodes, vector<vector<pair<ll, ll>>> &adj)
{
  pair<ll, ll> ans = {-1, -1}; // ans.first = node, ans.second = weight
  vector<bool> vis(nodes + 1, false);
  vector<ll> dist(nodes + 1, 0);
  queue<ll> q;
  q.push(src);
  vis[src] = true;
  while (q.size() > 0) {
    ll u = q.front();
    q.pop();
    for (auto [v, w] : adj[u]) {
      if (vis[v]) continue;
      dist[v] = dist[u] + w;
      q.push(v);
      vis[v] = true;
    }
  }
  for (ll i = 1; i <= nodes; i += 1) {
    if (dist[i] >= ans.second) {
      ans.first = i;
      ans.second = dist[i];
    }
  }
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  ll t = 1; cin >> t;
  for (ll test = 1; test <= t; test += 1) {
    cout << "Case " << test << ": ";
    ll nodes, edges; cin >> nodes;
    edges = nodes - 1;
    vector<vector<pair<ll, ll>>> adj(nodes + 1);
    for (ll i = 1; i <= edges; i += 1) {
      ll u, v, w; cin >> u >> v >> w;
      u += 1, v += 1;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }
    pair<ll, ll> currFurthest = furthestCalc(1, nodes, adj);
    pair<ll, ll> furthest = furthestCalc(currFurthest.first, nodes, adj);
    cout << furthest.second << endl;
  }
  return 0;
}
