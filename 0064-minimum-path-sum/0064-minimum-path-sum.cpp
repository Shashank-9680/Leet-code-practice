class Solution {
    int findMinSum(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(i==0&&j==0) return grid[i][j];
        if(i<0||j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = findMinSum(i-1, j, grid,dp);
    int left = findMinSum(i, j-1, grid,dp);

    int sum1 = (up == INT_MAX) ? INT_MAX : grid[i][j] + up;
    int sum2 = (left == INT_MAX) ? INT_MAX : grid[i][j] + left;
         return dp[i][j]= min(sum1,sum2);

    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();    
        vector<vector<int>>dp(n,vector<int>(m,-1));    
        return findMinSum(n-1,m-1,grid,dp);
    }
};