class Solution {
    int count(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i==0&&j==0) return 1;
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(grid[i][j]==1){
           return dp[i][j]=0;
        }
        
      
        int count1= count(i-1,j,grid,dp);
        int count2=count(i,j-1,grid,dp);
         return dp[i][j]= count1+count2;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return count(m-1,n-1,obstacleGrid,dp);
    }
};