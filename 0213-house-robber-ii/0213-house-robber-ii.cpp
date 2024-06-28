class Solution {
    int maximum(vector<int>& dp, vector<int>& nums, int n) {
        if (n == 0) return nums[0];
        if (n < 0) return 0;
        if (dp[n] != -1) return dp[n];
        
        int pick = nums[n] + maximum(dp, nums, n - 2);
        int notpick = 0 + maximum(dp, nums, n - 1);
        
        return dp[n] = max(pick, notpick);
    }
public:
    int rob(vector<int>& nums) {
    int n = nums.size();
        if (n == 1) return nums[0];
        
        vector<int> temp1, temp2;
        for (int i = 0; i < n; i++) {
            if (i != 0) temp1.push_back(nums[i]);
            if (i != n - 1) temp2.push_back(nums[i]);
        }
        
        vector<int> dp1(n - 1, -1);
        vector<int> dp2(n - 1, -1);
        
        return max(maximum(dp1, temp1, n - 2), maximum(dp2, temp2, n - 2));
       
        
    }
};