class Solution {
    int find(int i, vector<int>&dp){
        if(i==0) return 1;
        if(i==1) return 1;
        if(dp[i]!=-1) return dp[i];
        dp[i]= find(i-1,dp)+find(i-2,dp);
        return dp[i];
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return find(n,dp);
    }
};