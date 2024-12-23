//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
bool bs(vector<int> &arr, int k) {

    int low = 0, high = arr.size() - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (arr[mid] == k) return true;

        if (arr[mid] < k) low = mid + 1;

        else high = mid - 1;

    } 

  return false;

}


  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int target) {
           int n = mat.size();

    int m = mat[0].size();

    for (int i = 0; i < n; i++) {

//check once before performing binary search if the element is present in the row

  if(mat[i][0] <= target && target <= mat[i][m -1]) 

     if (bs(mat[i], target)) return true;

    }

    return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchRowMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends