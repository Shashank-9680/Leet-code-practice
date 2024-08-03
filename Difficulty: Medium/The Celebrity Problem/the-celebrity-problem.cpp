//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    
    int celebrity(vector<vector<int> >& mat) {
        int n=mat.size();
       vector<int>indegree(n,0);
       vector<int>outdegree(n,0);
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(mat[i][j]==1){
                indegree[j]++;
                outdegree[i]++;
               }
           }
       }
       if(n==1){
           return 0;
       }
       int ans=-1;
       for(int i=0;i<n;i++){
           if(indegree[i]==n-1&&outdegree[i]==0){
            ans=i;   
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends