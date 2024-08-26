//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int fxn(int i,int j,string pattern,string str,vector<vector<int>>&dp){                                                                              
    
    if(j<0&&i<0){
        return 1;
    }
    if(i<0&&j>=0){
        return 0;
    }
    if(j<0&&i>=0){
        for(int k=0;k<=i;k++){
            if(pattern[k]!='*'){
                return 0;
            }
        }
        return 1;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(pattern[i]=='?'){
       return dp[i][j]= fxn(i-1,j-1,pattern,str,dp);
    }
    if(pattern[i]==str[j]){
        return dp[i][j]= fxn(i-1,j-1,pattern,str,dp);
    }
    if(pattern[i]=='*'){
      return dp[i][j]= fxn(i-1,j,pattern,str,dp)|fxn(i,j-1,pattern,str,dp);
    }
    return dp[i][j]=0;
    }
  public:
    /*You are required to complete this method*/
    int wildCard(string pattern, string str) {
    int n=pattern.size();
    int m=str.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fxn(n-1,m-1,pattern,str,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends