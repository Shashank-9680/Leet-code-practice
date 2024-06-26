class Solution {
    int sum(int m,int n,vector<vector<int>>&grid,vector<vector<int>>&dp){
       
        if(m==0&&n==0) return grid[0][0];
       if (m < 0 || n < 0) return 1e9;
         if(dp[m][n]!=-1) return dp[m][n];
      // int top = INT_MAX, left = INT_MAX;
        int top = grid[m][n] + sum(m - 1, n, grid, dp);
        int left = grid[m][n] + sum(m, n - 1, grid, dp);
      
        return dp[m][n]= min(left,top);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return sum(m-1,n-1,grid,dp);
    }
};