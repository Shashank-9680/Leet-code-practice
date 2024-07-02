class Solution {
    int maximum(int i,int j,int cap,vector<int>&prices,vector<vector<vector<int>>>&dp,int n){
        if(n==i||cap==0) return 0;
         if(dp[i][j][cap]!=-1) return dp[i][j][cap];
        if(j==1){
           int take=-prices[i]+maximum(i+1,0,cap,prices,dp,n);
            int nottake=maximum(i+1,1,cap,prices,dp,n);
            return dp[i][j][cap]=max(take,nottake);
        }
        else{
              int take=prices[i]+maximum(i+1,1,cap-1,prices,dp,n);
            int nottake=maximum(i+1,0,cap,prices,dp,n);
             return dp[i][j][cap]=max(take,nottake);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return maximum(0,1,2,prices,dp,n);
    }
};