class Solution {
  public:
  
  int find(int i , int k, vector<int>& arr, vector<vector<int>> &dp){
    
    if(i == 0){
        if(k == 0 && arr[0] == 0) return 2;
        if(k == 0 || k == arr[0]) return 1;
        return 0;
    }

    if(dp[i][k] != -1) return dp[i][k];

    int take = 0;
    if(k >= arr[i]){
        take = find(i-1, k - arr[i], arr, dp);
    }

    int notTake = find(i-1, k, arr, dp);

    return dp[i][k] = (take + notTake);
  }

  int countPartitions(vector<int>& arr, int diff) {
       
       int n = arr.size();
       int sum = 0;

       for(int i = 0; i < n; i++){
           sum += arr[i];
       }

       if(sum < diff) return 0;
       if((sum - diff) % 2 != 0) return 0;

       int val = (sum - diff) / 2;

       vector<vector<int>> dp(n, vector<int>(val + 1, -1));
       
       return find(n - 1, val, arr, dp);
  }
};