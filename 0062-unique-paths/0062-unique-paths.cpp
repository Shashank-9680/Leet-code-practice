class Solution {
    int count(int i,int j,vector<vector<int>>&dp){
        if(i==0&&j==0) return 1;
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int count1= count(i-1,j,dp);
        int count2=count(i,j-1,dp);
        return dp[i][j]= count1+count2;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int count1=dp[i-1][j];
                int count2=dp[i][j-1];
                dp[i][j]=count1+count2;
            }
        }
       return dp[m-1][n-1];
    }
};