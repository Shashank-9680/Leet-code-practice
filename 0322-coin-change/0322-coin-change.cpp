class Solution {
    int minimum(int n,int amount,vector<int>coins,vector<vector<int>>&dp){
        if(n==0){
            if(amount%coins[n]==0) return amount/coins[n];
             else{
                 return 1e9;
             }
        }
        if(dp[n][amount]!=-1) return dp[n][amount];
            int notpick=minimum(n-1,amount,coins,dp);
            int pick=1e9;
            if(coins[n]<=amount){
                pick=1+minimum(n,amount-coins[n],coins,dp);
            }
            return dp[n][amount]=min(pick,notpick);
        
        
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int result = minimum(n - 1, amount, coins, dp);
         return (result >= 1e9) ? -1 : result;
    }
};