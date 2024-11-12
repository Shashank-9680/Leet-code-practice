//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
    static bool comp(vector<int>v1,vector<int>v2){
        return v1[1]<v2[1];
    }
  public:
    bool canAttend(vector<vector<int>> &arr) {
       sort(arr.begin(),arr.end(),comp);
       int start=arr[0][1];
       for(int i=1;i<arr.size();i++){
           if(start>arr[i][0]){
               return false;
           }
           start=arr[i][1];
       }
       return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        cin.ignore();
        Solution obj;
        bool ans = obj.canAttend(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends