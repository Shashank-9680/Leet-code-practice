class Solution {
     int lcs(string s1, string s2,vector<vector<int>>&dp) {

  int n = s1.size();
  int m = s2.size();


  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int i = 0; i <= m; i++) {
    dp[0][i] = 0;
  }

  for (int ind1 = 1; ind1 <= n; ind1++) {
    for (int ind2 = 1; ind2 <= m; ind2++) {
      if (s1[ind1 - 1] == s2[ind2 - 1])
        dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
      else
        dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
    }
  }
        return dp[n][m];
    }
public:
    int minDistance(string word1, string word2) {
      
        int n=word1.size();
        int m=word2.size();
          vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int value=lcs(word1,word2,dp);
        return n-value+m-value;
    }
};