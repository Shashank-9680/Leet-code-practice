class Solution {
    // int count(int m,int n,vector<vector<int>>&dp){
    //     if(m==0&&n==0) return 1;
    //     if(m<0||n<0) return 0;
    //     if(dp[m][n]!=-1) return dp[m][n];
    //     int left=count(m,n-1,dp);
    //     int right=count(m-1,n,dp);
    //     return dp[m][n]=left+right;
    // }
public:
    int uniquePaths(int m, int n) {
      vector<vector<int>>dp(m,vector<int>(n));
        // return count(m-1,n-1,dp);
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0){
                    dp[i][j]=1;
                    continue;
                }
                int up=0;
                int left=0;
                if(i>0){
                  up=dp[i-1][j];  
                }
                if(j>0){
                    left=dp[i][j-1];
                }
                dp[i][j]=left+up;
            }
        }
        return dp[m-1][n-1];
    }
};