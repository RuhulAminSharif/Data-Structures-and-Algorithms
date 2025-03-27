#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
#define inf 1e18
bool hasCycle = false;
vector<ll> bellmanFord(vector<vector<ll>>& edgeList, ll src, ll V )
{
    vector<ll> dist( V + 1, inf );
    dist[src] = 0LL;
    for( ll i = 1; i <= V; i += 1 ) {
        for( ll j = 0; j < edgeList.size(); j += 1 ) {
            ll u = edgeList[j][0];
            ll v = edgeList[j][1];
            ll w = edgeList[j][2];
            if( dist[u] + w < dist[v] ) {
                dist[v] = dist[u] + w ;
                if( i == V ) {
                    hasCycle = true;
                }
            }
        }
    }
    return dist;
}
vector<ll> dijkstra(vector<vector<pair<ll, ll>>> &adj, ll src, ll V)
{
    vector<ll> dist( V + 1, inf );
    set<pair<ll, ll>> st;
    st.insert( {0, src} );
    dist[src] = 0;
    while( st.size() > 0 ) {
        auto it = *(st.begin());
        ll node = it.second;
        st.erase(st.begin());
        for( auto it : adj[node] ) {
            ll adjNode = it.first;
            ll adjWeight = it.second;
            ll nextWeight = dist[node] + adjWeight;
            if( nextWeight < dist[adjNode] ) {
                st.erase( {dist[adjNode], adjNode} );
                dist[adjNode] = nextWeight;
                st.insert( { nextWeight, adjNode } );
            }
        }
    }
    return dist;
}
void johnsonAlgo(vector<vector<ll>>& edgeList, ll V )
{
    vector<vector<ll>> newEdgeList = edgeList;
    // adding new vertex -> 'V+1'
    ll newVertex = V + 1;
    for( ll i = 1; i <= V; i += 1 ) {
        newEdgeList.push_back( { newVertex, i, 0} );
    }
    vector<ll> h = bellmanFord( newEdgeList, newVertex, V + 1 );
    if( hasCycle ) {
        cout << "no" << endl;
        return ;
    }
    cout << "yes" << endl << endl;
    vector<vector<pair<ll, ll>>> adj ( newVertex + 1 );

    // Re-weight edges to remove negative weights
    for( ll i = 0; i < edgeList.size(); i += 1 ) {
        ll u = edgeList[i][0];
        ll v = edgeList[i][1];
        ll w = edgeList[i][2];
        ll newWeight = w + h[u] - h[v];
        adj[u].push_back( { v, newWeight } );
    }
    for( ll i = 1; i <= newVertex; i += 1 ) cout << h[i] << " ";
    cout << endl;

    vector<vector<ll>> shortestPaths(newVertex, vector<ll>( newVertex, inf));

    for( ll i = 1; i <= V; i += 1 ) {
        shortestPaths[i] = dijkstra( adj, i, V );
    }
    for( ll i = 1; i <= V; i += 1 ) {
        for( ll j = 1; j <= V; j += 1 ) {
            if( shortestPaths[i][j] == inf ) cout << "#" << " ";
            else cout << shortestPaths[i][j] + h[j] - h[i] << " ";
        }
        cout << endl;
    }
    return ;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1; cin >> t;
    for( ll g = 1; g <= t; g += 1 ) {
        hasCycle = false;
        cout << "graph " << g << " ";
        ll V, E; cin >> V >> E;
        vector<vector<ll>> edgeList( E, vector<ll>(3) );
        for( ll i = 0; i < E ; i += 1 ) {
            ll u, v, w; cin >> u >> v >> w;
            edgeList[i][0] = u;
            edgeList[i][1] = v;
            edgeList[i][2] = w;
        }
        johnsonAlgo( edgeList, V );
        cout << endl;
    }
    return 0;
}

/// https://www.spoj.com/problems/JHNSN/