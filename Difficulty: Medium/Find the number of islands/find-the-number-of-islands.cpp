//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    vector<pair<int,int>>dir={{-1,-1},{-1,0},{0,-1},{1,-1},{-1,1},{0,1},{1,0},{1,1}};
    
    void dfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&vis){
         int n=grid.size();
       int m=grid[0].size();
        vis[row][col]=1;
        for(auto it:dir){
            int nrow=row+it.first;
            int ncol=col+it.second;
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]){
                if(grid[nrow][ncol]=='1'){
                    dfs(nrow,ncol,grid,vis);
                }
            }
        }
        
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       vector<vector<int>>vis(n,vector<int>(m,0));
       int count=0;
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(!vis[i][j]&&grid[i][j]=='1'){
                   dfs(i,j,grid,vis);
                   count++;
               }
           }
       }
       return count;
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