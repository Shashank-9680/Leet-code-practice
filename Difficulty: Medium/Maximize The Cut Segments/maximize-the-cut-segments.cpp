//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    int maximum(int n,int x,int y,int z,vector<int>&dp){
        if(n<0) return INT_MIN;
        if(n==0){
            return 0;
        }
          if(dp[n]!=-1) return dp[n];
        int cl1=maximum(n-x, x, y, z, dp);
        int cl2=maximum(n-y, x, y, z, dp);
        int cl3=maximum(n-z, x, y, z, dp);
        
        return dp[n]=1+max(cl1, max(cl2, cl3));
    }
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>dp(n+1, -1);
        return max(0, maximum(n, x, y, z, dp));
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends