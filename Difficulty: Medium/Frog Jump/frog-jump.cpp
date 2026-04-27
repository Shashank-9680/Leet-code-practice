class Solution {
    int find(int i, vector<int>&height,vector<int>&dp){
        if(i==0){
            return 0;
        }
        
        int twoStep= INT_MAX;
        if(dp[i]!=-1) return dp[i];
        if(i>1){
            twoStep=find(i-2,height,dp)+abs(height[i]-height[i-2]);
        }
        int oneStep= find(i-1,height,dp)+abs(height[i]-height[i-1]);
        return dp[i]= min(twoStep,oneStep);
    }
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int>dp(n,-1);
        return find(n-1,height,dp);
        }
};