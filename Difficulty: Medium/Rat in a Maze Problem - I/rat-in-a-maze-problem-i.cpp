//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    vector<pair<int,int>>directions={{-1,0},{0,-1},{0,1},{1,0}};
  void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& mat, string path, vector<string>& ans) {
        int n = mat.size();
        int m = mat[0].size();
        
        // If destination is reached, add the path to the result
        if (i == n-1 && j == m-1) {
            ans.push_back(path);
            return;
        }
        
       
        vis[i][j] = 1;
      
        for (auto dir : directions) {
            int nrow = i + dir.first;
            int ncol = j + dir.second;
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 1) {
                if (dir == make_pair(-1, 0)) path.push_back('U'); 
                else if (dir == make_pair(0, -1)) path.push_back('L'); 
                else if (dir == make_pair(0, 1)) path.push_back('R'); 
                else if (dir == make_pair(1, 0)) path.push_back('D'); 
                
                dfs(nrow, ncol, vis, mat, path, ans);
                
                path.pop_back(); 
            }
        }
        
       
        vis[i][j] = 0;
    }
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        int n=mat.size();
        int m=mat[0].size();
     vector<vector<int>>vis(n,vector<int>(m,0));
        string path = "";
       vector<string>ans;
 if (mat[0][0] == 0) {
            return {};
        }
       dfs(0,0,vis,mat,path,ans);
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
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends