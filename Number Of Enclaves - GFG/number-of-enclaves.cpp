//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int r , int c ,vector<vector<int>>& grid, vector<vector<int>>&vis ){
         int m= grid.size(),n=grid[0].size();
        if(r<0 || r>=m || c<0 || c>=n || vis[r][c]==1 || grid[r][c]==0){
            return ;
        }
        vis[r][c]=1;
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        for(int i=0 ;i<4;i++){
            dfs(r+delRow[i],c+delCol[i],grid,vis);
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
         int m= grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0 ;i<m ;i++){
            for(int j=0;j<n ;j++){
                if(grid[i][j]==1 && (i==0 || j==0 || i==m-1 || j==n-1)){
                    dfs(i,j,grid,vis);
                }
            }
        }
        int count=0;
        for(int i=0 ;i<m ;i++){
            for(int j=0 ;j<n ;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    count++;
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends