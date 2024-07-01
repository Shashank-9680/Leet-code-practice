class Solution {
//    int count(int n, int sum, vector<int>& arr, map<pair<int, int>, int>& dp) {
// //         // Base case
//         if (n == 0) {
//             if (sum == 0 && arr[0] == 0) return 2;
//             if (arr[0] == sum || sum == 0) return 1;
//             return 0;
//         }
        
//         // Check if the result is already computed
//         if (dp.find({n, sum}) != dp.end()) return dp[{n, sum}];
        
//         // Do not pick the current element
//         int notpick = count(n - 1, sum, arr, dp);
        
//         // Pick the current element
//         int pick = 0;
//         if (arr[n] <= sum) {
//             pick = count(n - 1, sum - arr[n], arr, dp);
//         }
        
//         // Store the result in the map and return
//         return dp[{n, sum}] = (pick + notpick) ;
//     }
public:
    int findTargetSumWays(vector<int>& arr, int d) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);

        // If the required conditions are not met, return 0
        if ((sum + d) % 2 != 0 || d > sum) return 0;

        int target = (sum + d) / 2;
       if(target<0) return 0;
        // Initialize the dp array
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        
        // Base case: There's one way to make sum 0 - by picking nothing
        if (arr[0] == 0) {
        dp[0][0] = 2; // Two ways to make sum 0 with first element 0: include or exclude it
    } else {
        dp[0][0] = 1; // One way to make sum 0 by excluding the first element
    }

    if (arr[0] != 0 && arr[0] <= target) {
        dp[0][arr[0]] = 1; // One way to make sum arr[0] by including the first element
    }
       
        
         // There's one way to get the sum equal to the first element

        // Fill the dp array
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= target; j++) {
                int notpick = dp[i - 1][j];
                int pick = 0;
                if (arr[i] <= j) {
                    pick = dp[i - 1][j - arr[i]];
                }
                dp[i][j] = (pick + notpick);
            }
        }
        return dp[n - 1][target];
    }
};