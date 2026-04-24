class Solution {
    
    int find(int i, vector<int>&height,vector<int>&dp){
        if(i==0) return 0;
        if(dp[i]!=-1) return dp[i];
        int step1=find(i-1,height,dp)+abs(height[i]-height[i-1]);
        int step2=INT_MAX;
        if(i>1){
            step2=find(i-2,height,dp)+abs(height[i]-height[i-2]);
        }
        dp[i]= min(step1,step2);
        return dp[i];
    }
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int>dp(n,-1);
        return find(n-1,height,dp);
    }
};