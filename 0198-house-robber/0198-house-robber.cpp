class Solution {
    int find(int i, vector<int>&nums,vector<int>&dp){
        if(i<0) return 0;
        if(i==0) return nums[0];
        if(dp[i]!=-1) return dp[i];
        int take= find(i-2,nums,dp)+nums[i];
        int notTake=find(i-1,nums,dp);
        dp[i]= max(take,notTake);
        return dp[i];
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int n=nums.size();
        vector<int>dp(n+1,0);
        // return find(n-1,nums,dp);
        dp[0]=0;
        dp[1]=nums[0];
        // dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<=n;i++){
            
             int take= dp[i-2]+nums[i-1];

             int notTake= dp[i-1];
             dp[i]=max(take,notTake);
        }
        return dp[n];
    }
};