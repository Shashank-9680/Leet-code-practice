class Solution {

    bool find(int i, int sum, vector<int>&nums, vector<vector<int>>&dp){
        if(sum==0) return true;
        if(i==0) return nums[0]==sum;
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool take=false;
        if(sum>=nums[i]){
            take=find(i-1,sum-nums[i],nums,dp);
        }
        bool notTake=find(i-1,sum,nums,dp);
        return dp[i][sum]= take||notTake;

    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
        }
       
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return find(n-1,target,nums,dp);
    }
};