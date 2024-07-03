class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
       vector<int>dp(n,1),hash(n);
        int maxi=0;
         int lastindex=0;
       for(int i=0;i<n;i++){
           hash[i]=i;
           for(int j=0;j<i;j++){
               if(arr[i]%arr[j]==0&& 1+dp[j]>dp[i]){
                   dp[i]=1+dp[j];
                   hash[i]=j;
               }
           }
          if(dp[i]>maxi){
           maxi=dp[i];
           lastindex=i;
       }
           
       }
      
     vector<int>ans(maxi);
     ans[0]=arr[lastindex];
     int idx=1;
     while(hash[lastindex]!=lastindex){
         lastindex=hash[lastindex];
         ans[idx++]=arr[lastindex];
     }
     reverse(ans.begin(),ans.end());
     return ans;   
    }
};