class Solution {
    
int find(int i, int j, vector<vector<int>>& points, vector<vector<int>>&dp){
    if(i == 0) return points[0][j];


    int maxi = INT_MIN;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int k = 0; k <= 2; k++){
        if(k != j){
            maxi = max(maxi, points[i][j] + find(i-1, k, points,dp));
        }
    }
    return dp[i][j]= maxi;
}
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int ans = 0;
        vector<vector<int>>dp(n,vector<int>(3,-1));
    for(int j = 0; j <= 2; j++){
       
        ans = max(ans, find(n-1, j, mat,dp));
    }
    return ans;
        
    }
};

