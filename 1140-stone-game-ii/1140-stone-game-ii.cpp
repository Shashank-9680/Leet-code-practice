class Solution {
    int n;

    int solve(vector<int>& piles, vector<vector<vector<int>>>& dp, int person, int i, int m) {
        if (i >= n) {
            return 0;
        }
        if (dp[person][i][m] != -1) { // Check if the value has been computed
            return dp[person][i][m];
        }

        int stones = 0;
        int result = person == 1 ? INT_MIN : INT_MAX; // Initialize result based on the current player

        for (int x = 1; x <= min(2 * m, n - i); x++) {
            stones += piles[i + x - 1];
            if (person == 1) {
                result = max(result, stones + solve(piles, dp, 0, i + x, max(x, m)));
            } else {
                result = min(result, solve(piles, dp, 1, i + x, max(x, m)));
            }
        }

        return dp[person][i][m] = result;
    }

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n+1, vector<int>(n+1, -1)));
        return solve(piles, dp, 1, 0, 1);
    }
};
