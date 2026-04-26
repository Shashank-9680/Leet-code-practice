class Solution {
    bool find(int i, int target, vector<int>&arr,vector<vector<int>>&dp){
        if(target==0){
            return true;
        }
        if(i==0){
            if(target==arr[0]){
                return true;
            }
            else{
                return false;
            }
        }
        if(dp[i][target]!=-1) return (dp[i][target]==0 ? false:true);
        
       bool take=false;
       if(target>=arr[i]){
          take= find(i-1,target-arr[i],arr,dp);
       }
        
        bool notTake=find(i-1,target,arr,dp);
        
        bool val= take||notTake;
        return dp[i][target] = val==true? 1:0;
    }
    
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return find(n-1,sum,arr,dp);
    }
};