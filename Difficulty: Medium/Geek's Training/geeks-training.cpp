class Solution {
    
    int find(int i,int j, vector<vector<int>>&mat,vector<vector<int>>&dp){
        if(i==0) return mat[0][j]; 
        if(dp[i][j]!=-1) return dp[i][j];
         int maxi=INT_MIN;
        for(int k=0;k<3;k++){
            if(k!=j){
                maxi=max(maxi,mat[i][j]+ find(i-1,k,mat,dp));
            }
        }
        return dp[i][j]= maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n=mat.size();
        int maxi=INT_MIN;
        vector<vector<int>>dp(n,vector<int>(3,-1));
       for(int i=0;i<3;i++){
          maxi= max(maxi,find(n-1,i,mat,dp));
       }
       return maxi;
        
    }
};