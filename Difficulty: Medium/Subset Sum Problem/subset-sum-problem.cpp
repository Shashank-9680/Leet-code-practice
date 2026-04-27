class Solution {
    bool find(int i, int sum, vector<int>&arr, vector<vector<int>>&dp){
        if(sum==0){
            return true;
        }
        if(i==0) return arr[0]==sum;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int pick=false;
        if(sum>=arr[i]){
            pick=find(i-1,sum-arr[i],arr,dp);
        }
        int notpick=find(i-1,sum,arr,dp);
        return dp[i][sum]= pick||notpick;
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return find(n-1,sum,arr,dp);
    }
};