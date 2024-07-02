class Solution {
      int maximum(int i,int j,vector<int>&prices,vector<vector<int>>&dp,int n,int fee){
        if(i==n){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(j==1){
           int take=-prices[i]+maximum(i+1,0,prices,dp,n,fee);
            int nottake=maximum(i+1,1,prices,dp,n,fee);
            return dp[i][j]=max(take,nottake);
        }
        else{
              int take=prices[i]-fee+maximum(i+1,1,prices,dp,n,fee);
            int nottake=maximum(i+1,0,prices,dp,n,fee);
             return dp[i][j]=max(take,nottake);
        }
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
           int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return maximum(0,1,prices,dp,n,fee);
    }
};