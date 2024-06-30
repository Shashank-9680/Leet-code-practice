class Solution {
   int count(int n, int sum, vector<int>& arr, map<pair<int, int>, int>& dp) {
        // Base case
        if (n == 0) {
            if (sum == 0 && arr[0] == 0) return 2;
            if (arr[0] == sum || sum == 0) return 1;
            return 0;
        }
        
        // Check if the result is already computed
        if (dp.find({n, sum}) != dp.end()) return dp[{n, sum}];
        
        // Do not pick the current element
        int notpick = count(n - 1, sum, arr, dp);
        
        // Pick the current element
        int pick = 0;
        if (arr[n] <= sum) {
            pick = count(n - 1, sum - arr[n], arr, dp);
        }
        
        // Store the result in the map and return
        return dp[{n, sum}] = (pick + notpick) ;
    }
public:
    int findTargetSumWays(vector<int>& arr, int d) {
          map<pair<int,int>,int> dp;
         int sum = accumulate(arr.begin(), arr.end(), 0);
        if ((sum + d) % 2 != 0 || d > sum) return 0;
         
        int target = (sum + d) / 2;
        return count(arr.size()-1,target,arr,dp);
    }
};