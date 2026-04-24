class Solution {
    int find(int i,vector<int>&nums,vector<int>&dp){
        if(i==0) return nums[0];
        if(i==1) return max(nums[0],nums[1]);
        if(dp[i]!=-1) return dp[i];
        int take=nums[i]+find(i-2,nums,dp);
        int notTake=find(i-1,nums,dp);
        dp[i]= max(take,notTake);
        return dp[i];

    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
       return find(n-1,nums,dp);


    }
};