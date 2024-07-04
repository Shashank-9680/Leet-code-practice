class Solution {
    int maximum(int i,int j,vector<int>&nums,vector<vector<int>>dp){
        if(i>j){
            return 0;
            
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=-1e9;
        for(int inx=i;inx<=j;inx++){
           int steps=nums[j+1]*nums[i-1]*nums[inx]+maximum(i,inx-1,nums,dp)+maximum(inx+1,j,nums,dp);
            maxi=max(maxi,steps);
        }
        return dp[i][j]=maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
       int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        // return maximum(1,n,nums,dp);
        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){
               int maxi=-1e9;
        for(int inx=i;inx<=j;inx++){
           int steps=nums[j+1]*nums[i-1]*nums[inx]+dp[i][inx-1]+dp[inx+1][j];
            dp[i][j]=max(dp[i][j],steps);
        }
       
            }
        }
        return dp[1][n];
    }
};