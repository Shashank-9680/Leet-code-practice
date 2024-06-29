class Solution {
    int minimum(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp, int n) {
        if (j < 0 || j >= n) return 1e9; // Out of bounds case
        if (i == 0) return matrix[0][j]; // Base case
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int top = matrix[i][j] + minimum(i - 1, j, matrix, dp, n);
        int left = matrix[i][j] + minimum(i - 1, j - 1, matrix, dp, n);
        int right = matrix[i][j] + minimum(i - 1, j + 1, matrix, dp, n);
        
        return dp[i][j] = min(top, min(left, right));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        // Initialize the first row
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Fill the dp table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int top = matrix[i][j] + dp[i-1][j];
                int left = matrix[i][j];
                if (j > 0) { // Check for left boundary
                    left += dp[i-1][j-1];
                } else {
                    left = 1e9; // Out of bounds
                }

                int right = matrix[i][j];
                if (j < n-1) { // Check for right boundary
                    right += dp[i-1][j+1];
                } else {
                    right = 1e9; // Out of bounds
                }

                dp[i][j] = min(top, min(left, right));
            }
        }

        // Find the minimum value in the last row
        int mini = INT_MAX;
        for (int j = 0; j < n; j++) {
            mini = min(mini, dp[n-1][j]);
        }

        return mini;
      
    }
};