//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs(int i , int j ,vector<vector<char>>& grid, vector<vector<int>>& visited){
         int m =  grid.size();
        int n = grid[0].size();
        if(  i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0' || visited[i][j]){
              return ;
        }
           visited[i][j] =1 ;
           dfs(i , j+1 ,grid , visited);
dfs(i-1 , j+1 ,grid , visited);
dfs(i+1 , j+1 ,grid , visited);
              dfs(i+1 , j ,grid , visited);
dfs(i+1 , j-1 ,grid , visited);
                dfs(i , j-1 ,grid , visited);
dfs(i-1 , j-1 ,grid , visited);
                  dfs(i-1 , j ,grid , visited);
                  return ;

    }
    int numIslands(vector<vector<char>>& grid) {
        int m =  grid.size();
        int n = grid[0].size();
        vector<int> row(n, 0);
	vector<vector<int>> visited(m, row) ;
      
        int count = 0;
        for(int r =0 ; r< m ;r++){
            for(int c=0 ;c< n ;c++){
                if(grid[r][c] == '1' && !visited[r][c] ){
                    count++;
                    dfs(r , c , grid , visited);
                }
            }
        }
        return count ;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends