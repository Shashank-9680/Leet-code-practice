//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &arr,
                                       vector<int> &newInterval) {
        vector<vector<int>>ans;
        bool inserted = false;
    for (int i = 0; i < arr.size(); i++) {
        if (newInterval[0] < arr[i][0]) {
            arr.insert(arr.begin() + i, newInterval);
            inserted = true;
            break;
        }
    }
    if (!inserted) {
        arr.push_back(newInterval);
    }

    for (int i = 0; i < arr.size(); i++) {
        if (ans.empty() || ans.back()[1] < arr[i][0]) {
            ans.push_back(arr[i]);
        } else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
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
        int N;
        cin >> N;
        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        vector<int> newInterval(2);
        cin >> newInterval[0] >> newInterval[1];

        Solution obj;
        vector<vector<int>> ans = obj.insertInterval(intervals, newInterval);
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[" << ans[i][0] << ',' << ans[i][1] << ']';
            if (i != (ans.size() - 1))
                cout << ",";
        }
        cout << "]" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends