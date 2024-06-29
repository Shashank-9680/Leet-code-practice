class Solution {
public:
    bool canPartition(vector<int>& nums) {
       int sum=0;
     int n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
        }
         if(sum%2!=0) return false;
        int target=sum/2;
           vector<vector<bool>>dp(n,vector<bool>(target+1,false));
       
        for(int i=0;i<n;i++) dp[i][0]=true;
       if (nums[0] <= target) {
        dp[0][nums[0]] = true;
    }
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool notpick=dp[i-1][j];
                bool pick=false;
                if(nums[i]<=j){
                    pick=dp[i-1][j-nums[i]];
                }
                dp[i][j] = pick || notpick;
            }
        }
        return dp[n-1][target];
    }
};