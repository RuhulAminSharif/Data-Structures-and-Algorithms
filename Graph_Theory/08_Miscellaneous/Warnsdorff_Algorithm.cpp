#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

vector<pair<int, int>> knightMoves = {
  {-1, -2},   
  {-2, -1},   
  {-2, 1},  
  {-1, 2}, 
  {1, 2}, 
  {2, 1}, 
  {2, -1},
  {1, -2}
};

bool isValid( ll x, ll y, vector<vector<ll>>& grid )
{
  return x >= 1 && x <= 8 && y >= 1 && y <= 8 && grid[x][y] == -1;
}

ll countMoves( ll x, ll y, vector<vector<ll>>& grid ) 
{
  ll cnt = 0;
  for( auto move : knightMoves ) {
    ll nx = x + move.first;
    ll ny = y + move.second;
    if( isValid( nx, ny, grid ) ) {
      cnt += 1;
    }
  }
  return cnt;
}
// Warnsdorff's Algorithm
void knightTour(ll srcX, ll srcY, vector<vector<ll>>& grid ) 
{
  ll x = srcX, y = srcY;
  for( ll i = 1; i <= 64; i += 1 ) {
    grid[x][y] = i;
    ll minMove = 10, nextX = -1, nextY = -1;
    for( auto move: knightMoves ) {
      ll nx = x + move.first;
      ll ny = y + move.second;
      if( isValid( nx, ny, grid ) ) {
        ll currMove = countMoves( nx, ny, grid );
        if( currMove < minMove ) {
          minMove = currMove;
          nextX = nx;
          nextY = ny;
        }
      }
    }
    if (nextX == -1 || nextY == -1) {
      break;
    }
    x = nextX;
    y = nextY;
  }
  return ;
}
int main() {
    fast_io();
    ll srcX, srcY; cin >> srcY >> srcX;
    vector<vector<ll>> grid( 9, vector<ll> ( 9, -1 ) );
    knightTour( srcX, srcY, grid );
    for( ll x = 1; x <= 8; x += 1 ) {
      for( ll y = 1; y <= 8; y += 1 ) {
        cout << grid[x][y] <<  ' ';
      }
      cout << endl;
    }
    
    return 0;
}
