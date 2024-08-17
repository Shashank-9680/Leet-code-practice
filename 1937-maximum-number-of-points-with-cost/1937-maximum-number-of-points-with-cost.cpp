class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        
      
        vector<vector<long long>> dp(n, vector<long long>(m, 0));
       
        for (int j = 0; j < m; j++) {
            dp[0][j] = points[0][j];
        }
        
       
        for (int i = 1; i < n; i++) {
            // Create an auxiliary array to optimize the left and right traversal
            vector<long long> left(m, 0), right(m, 0);
            
            // Left-to-right pass: Calculate maximum possible value for dp[i][j] considering left side
            left[0] = dp[i-1][0];
            for (int j = 1; j < m; j++) {
                left[j] = max(left[j-1], dp[i-1][j] + j);
            }
            
            // Right-to-left pass: Calculate maximum possible value for dp[i][j] considering right side
            right[m-1] = dp[i-1][m-1] - (m-1);
            for (int j = m-2; j >= 0; j--) {
                right[j] = max(right[j+1], dp[i-1][j] - j);
            }
            
            // Calculate dp for the current row using the left and right arrays
            for (int j = 0; j < m; j++) {
                dp[i][j] = points[i][j] + max(left[j] - j, right[j] + j);
            }
        }
        
        // The answer is the maximum value in the last row
        long long result = 0;
        for (int j = 0; j < m; j++) {
            result = max(result, dp[n-1][j]);
        }
        
        return result;
    }
};
