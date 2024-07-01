class Solution {
    int maximum(int n,int m,string text1,string text2,vector<vector<int>>dp){
        if(n<0||m<0){
            return 0;
        }
        if(dp[n][m]!=-1) return dp[n][m];
        if(text1[n]==text2[m]){
            return dp[n][m]=1+ maximum(n-1,m-1,text1,text2,dp);
        }
        else{
            return dp[n][m]=max(maximum(n-1,m,text1,text2,dp),maximum(n,m-1,text1,text2,dp));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return maximum(n-1,m-1,text1,text2,dp);
      

        // Fill the DP table iteratively
        for (int i = 0; i <=n; i++) {
            for (int j = 0; j <=m; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0; // Base case initialization
                } else if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // The answer is in dp[n][m]
        return dp[n][m];
    }
};