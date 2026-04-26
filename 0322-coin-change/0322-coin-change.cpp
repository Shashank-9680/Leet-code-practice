class Solution {
    int find(int i,int target, vector<int>&coins,vector<vector<int>>&dp){
        if(target==0){
            return 0;
        }
        if(i==0){
            if(target%coins[0]==0){
                return target/coins[0];
            }
            return 1e9;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int take=1e9;
        if(target>=coins[i]){
           take=1+find(i,target-coins[i],coins,dp);
        }
        int notTake=find(i-1,target,coins,dp);
        return dp[i][target]= min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return find(n-1,amount,coins,dp)==1e9? -1:find(n-1,amount,coins,dp);
    }
};