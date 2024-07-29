//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
     int countOne(vector<int>arr,int n){
       
        // int low=0;
        // int high=n-1;
        int ans=-1;
       
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                ans=i;
                break;
            }
        }
        if(ans==-1){
            return 0;
        }
        return n-ans;
    }
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
       int count=0;
        int index=-1;
        int n=arr.size();
        int m=arr[0].size();
       for(int i=0;i<n;i++){
           int value=countOne(arr[i], m);
           if(value>count){
             count=value;
              index=i;
           }
       }
       return index;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends