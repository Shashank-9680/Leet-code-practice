class Solution {
    int find(int i , vector<int>&nums, vector<int>&dp){
        if(i==0) return nums[0];
        if(i==1) return max(nums[0],nums[1]);
        if(dp[i]!=-1) return dp[i];
        int pick= nums[i]+find(i-2,nums,dp);
        int notPick= find(i-1,nums,dp);
        return dp[i]= max(pick,notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        if(nums.size()==1) return nums[0];
        int prev2=nums[0];
        int prev1=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int pick=nums[i]+prev2;
            int notPick=prev1;
           int curr=max(pick,notPick);
           prev2=prev1;
           prev1=curr;
        }
        return prev1;
    }
};