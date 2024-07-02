class Solution {
    // int maximum(int i,int j,vector<int>&prices,vector<vector<int>>&dp,int n){
    //     if(i==n){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(j==1){
    //        int take=-prices[i]+maximum(i+1,0,prices,dp,n);
    //         int nottake=maximum(i+1,1,prices,dp,n);
    //         return dp[i][j]=max(take,nottake);
    //     }
    //     else{
    //           int take=prices[i]+maximum(i+1,1,prices,dp,n);
    //         int nottake=maximum(i+1,0,prices,dp,n);
    //          return dp[i][j]=max(take,nottake);
    //     }
    // }
public:
    int maxProfit(vector<int>& a) {
        // int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return maximum(0,1,prices,dp,n);
        
// @dhairyarajbabbar7584
// 2 years ago
// my approach of this question

        int curr=a[0];
        int profit=0;
        for(int i=1;i<a.size();i++){
            if(a[i]<curr) curr=a[i];
            else if(a[i]>curr) {
                profit+=a[i]-curr;
                curr=a[i];
            }
        }
        return profit;
    }
    
};