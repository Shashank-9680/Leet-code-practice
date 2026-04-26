class Solution {
    int find(int i, int amount, vector<int>&coins,vector<vector<int>>&dp){
        if(amount==0) return 1;
        if(i==0){
            if(amount%coins[0]==0) return 1;
            return 0;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take=0;
        if(amount>=coins[i]){
             take=find(i,amount-coins[i],coins,dp);
        }
        int notTake=find(i-1,amount,coins,dp);
        return dp[i][amount]=take+notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return find(n-1,amount,coins,dp);
    }
};