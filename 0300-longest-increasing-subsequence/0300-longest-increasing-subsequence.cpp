class Solution {
    int maximum(int i, int j, vector<vector<int>>& dp, vector<int>& nums, int n) {
        if (i == n) return 0;
        if (dp[i][j+1] != -1) return dp[i][j+1];
        
        int nontake = maximum(i + 1, j, dp, nums, n);
        int take = 0;
        
        if (j == -1 || nums[i] > nums[j]) {
            take = 1 + maximum(i + 1, i, dp, nums, n);  // Change j to i here
        }
        
        return dp[i][j+1] = max(take, nontake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
      int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return maximum(0,-1,dp,nums,n);
    }
};