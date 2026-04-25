class Solution {
    int findMinSum(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(i==0&&j==0) return grid[i][j];
        if(i<0||j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = grid[i][j] +findMinSum(i-1, j, grid,dp);
    int left = grid[i][j]+findMinSum(i, j-1, grid,dp);

    // int sum1 = (up == INT_MAX) ? INT_MAX : grid[i][j] + up;
    // int sum2 = (left == INT_MAX) ? INT_MAX : grid[i][j] + left;
         return dp[i][j]= min(up,left);

    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();    
        vector<vector<int>>dp(n,vector<int>(m,0));   
        dp[0][0]=grid[0][0];
        for(int i=1;i<n;i++){
          dp[i][0]=grid[i][0]+dp[i-1][0];
        }
        for(int i=1;i<m;i++){
            dp[0][i]=grid[0][i]+dp[0][i-1];
        }
        for(int i=1;i<n;i++){
           for(int j=1;j<m;j++){
           int sum1 = grid[i][j]+ dp[i-1][j];
           int sum2 = grid[i][j]+dp[i][j-1];
               dp[i][j]= min(sum1,sum2);
           }
        }

        return dp[n-1][m-1];
    }
};