//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	int minimum(int i,int j,vector<vector<int>>&dp,string str1,string str2){
	    if(i<0&&j<0)return 0;
	    if(i<0)return j+1;
	    if(j<0) return i+1;
	    if(dp[i][j]!=-1) return dp[i][j];
	    if(str1[i]==str2[j]){
	        return dp[i][j]=minimum(i-1,j-1,dp,str1,str2);
	    }
	    if(str1[i]!=str2[j]){
	        int ins=1+minimum(i,j-1,dp,str1,str2);
	        int del=1+minimum(i-1,j,dp,str1,str2);
	        return dp[i][j]=min(ins,del);
	    }
	}	

	public:
	int minOperations(string str1, string str2) 
	{ 
	    int n=str1.size();
	    int m=str2.size();
	    vector<vector<int>>dp(n,vector<int>(m,-1));
	    return minimum(n-1,m-1,dp,str1,str2);
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends