class Solution {
public:
    int find(vector<int>& dp, int i){
        if(i == 0) return 1;
        if(i == 1) return 1;

        if(dp[i] != -1) return dp[i];

        int left = find(dp, i-1);
        int right = find(dp, i-2);

        return dp[i] = left + right;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return find(dp, n);
    }
};