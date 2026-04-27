class Solution {
    int find(int i,vector<int>&dp){
     if(i==0) return 1;
     if(i==1) return 1;
     if(dp[i]!=-1) return dp[i];
     return dp[i]= find(i-1,dp)+find(i-2,dp);
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }

        return dp[n];
    }
};