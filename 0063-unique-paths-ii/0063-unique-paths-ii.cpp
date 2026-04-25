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
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=1;
       for(int i=1;i<m;i++){
        if(obstacleGrid[i][0]==1){
            dp[i][0]=0;
        }
        else{
           dp[i][0]=dp[i-1][0];
        }
       }

       for(int i=1;i<n;i++){
        if(obstacleGrid[0][i]==1){
            dp[0][i]=0;
        }
        else{
           dp[0][i]=dp[0][i-1];

        }
       }

       for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(obstacleGrid[i][j]==1){
                dp[i][j]=0;
                continue;
            }
            int count1=dp[i-1][j];
            int count2=dp[i][j-1];
            dp[i][j]=count1+count2;
        }
       }
       return dp[m-1][n-1];
    }
};