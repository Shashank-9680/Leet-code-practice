//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    // int minimum(int i,int k,vector<int>&dp,vector<int>arr){
    //     if(i<=0) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int ans=INT_MAX;
    //     for(int jump=1;jump<=k;jump++){
    //         if(i-jump>=0){
    // int energy = minimum(i-jump,k, dp, arr) + abs(arr[i] -arr[i - jump]);
    //           ans=min(ans,energy); 
    //         }
    //     } 
    
    // }
  public:
    int minimizeCost(int k, vector<int>& arr) {
        int n=arr.size();
      vector<int>dp(n,0);
     for(int i=1;i<n;i++){
         int ans=INT_MAX;
          for(int jump=1;jump<=k;jump++){
            if(i-jump>=0){
           int energy =dp[i-jump] + abs(arr[i] -arr[i - jump]);
               ans=min(ans,energy); 
            }
        } 
        dp[i]=ans;
     }
     return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends