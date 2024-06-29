class Solution {
    int minimum(vector<vector<int>>&triangle,int i,int j,vector<vector<int>>&dp,int n){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==n-1){
                return triangle[i][j];
        }
        
        int down=triangle[i][j]+minimum(triangle,i+1,j,dp,n);
        int diagonal=triangle[i][j]+minimum(triangle,i+1,j+1,dp,n);
        return dp[i][j]=min(down,diagonal);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return minimum(triangle,0,0,dp,n);
    }
};