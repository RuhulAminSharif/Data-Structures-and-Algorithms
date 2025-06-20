#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> transpose( vector<vector<int>> mat )
{
  int dimX = mat.size();
  int dimY = mat[0].size();
  vector<vector<int>> ans(dimY, vector<int>(dimX));
  for( int i = 0; i < dimX; i += 1 ) {
    for( int j = 0; j < dimY; j += 1 ) {
      ans[j][i] = mat[i][j];
    }
  }
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int m, n; cin >> m >> n;
  vector<vector<int>>mat(m, vector<int>(n));
  for( int i = 0; i < m; i += 1 ) {
    for( int j = 0; j < n; j += 1 ) {
      cin >> mat[i][j];
    }
  }
  vector<vector<int>> ans = transpose(mat);
  for( int i = 0; i < n; i += 1 ) {
    for( int j = 0; j < m; j += 1 ) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}