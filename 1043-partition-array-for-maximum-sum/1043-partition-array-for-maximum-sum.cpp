class Solution {
    int maximum(int i,int n,vector<int>&arr,vector<int>&dp,int k){
        if(i==n){
            return 0;
        }
        int len=0;
        int maxi=INT_MIN;
        int maxans=INT_MIN;
        if(dp[i]!=-1) return dp[i];
        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum=maxi*(len)+maximum(j+1,n,arr,dp,k);
            maxans=max(maxans,sum);
        }
        return dp[i]=maxans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       int n=arr.size();
        vector<int>dp(n,-1);
        return maximum(0,n,arr,dp,k);
    }
};