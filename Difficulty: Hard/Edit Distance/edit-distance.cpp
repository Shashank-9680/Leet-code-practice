//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int minimum(int i,int j,string str1,string str2,vector<vector<int>>&dp){
        
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(str1[i]==str2[j]){
            return minimum(i-1,j-1,str1,str2,dp);
        }
        int r=1+minimum(i-1,j-1,str1,str2,dp);
        int d=1+minimum(i-1,j,str1,str2,dp);
        int in=1+minimum(i,j-1,str1,str2,dp);
        return dp[i][j]=min(r,min(d,in));
        
    }
  public:
    int editDistance(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return minimum(n-1,m-1,str1,str2,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends