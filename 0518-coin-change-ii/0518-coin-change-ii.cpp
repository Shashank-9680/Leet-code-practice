class Solution {
    int count(int n,int amount,vector<int>coins,vector<vector<int>>&dp){
       // if (amount == 0) {
       //      return 1;
       //  }
        
        // If no coins left or amount is negative, no valid way to form the amount
      
        if(n==0){
            return (amount%coins[n]==0); 
        }
      
        if(dp[n][amount]!=-1) return dp[n][amount];
        int notpick=count(n-1,amount,coins,dp);
        int pick=0;
        if(coins[n]<=amount){
            pick=count(n,amount-coins[n],coins,dp);
            
        }
        return dp[n][amount]=pick+notpick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
       vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return count(n-1,amount,coins,dp);
    }
};