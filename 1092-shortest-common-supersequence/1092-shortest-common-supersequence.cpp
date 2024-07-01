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
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n=str1.size();
        int m=str2.size();
          vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));
        int val=lcs(str1,str2,dp);
        
        int len=n+m-val;
        string s="";
        for(int i=0;i<len;i++){
           s+="$";
        }
        int index=len-1;
        int i=n;
        int j=m;
        while(i>0&&j>0){
            if(str1[i-1]==str2[j-1]){
                s[index]=str1[i-1];
                index--;
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                s[index]=str1[i-1];
                index--;
                i--;
            }
            else{
                s[index]=str2[j-1];
                index--;
                j--;
            }
        }
        while(i>0){
            s[index]=str1[i-1];
            index--;
            i--;
        }
        while(j>0){
            s[index]=str2[j-1];
            index--;
            j--;
        }
        return s;
    }
};