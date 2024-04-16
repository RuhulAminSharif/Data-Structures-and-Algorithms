// https://leetcode.com/problems/maximal-rectangle/description/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define inf 1e18
const ll mod = 1e9+7;
int largestRectangleArea(vector<int>& heights) {
    int len = heights.size();
    int maxArea = 0;
    stack < int > st;
    for( int idx = 0; idx <= len; idx += 1 ) {
        while ( st.size() && ( idx == len || heights[idx] <= heights[st.top()] ) ) {
            int curr_height = heights[ st.top() ];
            st.pop();
            int width;
            if( st.size() ) width = idx - st.top() - 1;
            else width = idx;
            maxArea = max(maxArea, width * curr_height);
        }
        st.push( idx );
    }
    return maxArea;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<int> heights ( m , 0 ) ;
    int ans = 0;
    for( int i = 0; i < n; i += 1 ) {
        for( int j = 0; j < m; j += 1 ) {
            if( matrix[i][j] == '1' ) {
                heights[j] += 1;
            } else {
                heights[j] = 0;
            }
        }
        ans = max( ans, largestRectangleArea( heights ) );
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}
