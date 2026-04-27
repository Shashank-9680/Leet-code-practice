// User function Template for C++

class Solution {
    
    int find(int i ,int w, vector<int>&price, vector<vector<int>>&dp){
        if(w==0){
            return 0;
        }
        if(i==1){
            return price[0]*w;
        }
        if(dp[i][w]!=-1) return dp[i][w];
        int take=0;
        if(w>=i){
            take=price[i-1]+find(i,w-i,price,dp);
        }
        int notTake= find(i-1,w,price,dp);
        return dp[i][w]=max(take,notTake);
    }
  public:
    int cutRod(vector<int> &price) {
        
        int n=price.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return find(n,n,price,dp);
        
    }
};
    