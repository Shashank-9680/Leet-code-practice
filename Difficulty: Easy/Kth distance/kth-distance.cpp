//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
       unordered_map<int, int> m;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            // Check if the current element already exists in the map
            if (m.find(arr[i]) != m.end()) {
                return true;  // Duplicate found within distance k
            }
            
            // Add the current element to the map
            m[arr[i]]++;

            // Remove the element that is more than 'k' distance away from the current index
            if (i >= k) {
                m[arr[i - k]]--;
                if (m[arr[i - k]] == 0) {
                    m.erase(arr[i - k]);
                }
            }
        }
        
        return false;  
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        bool res = obj.checkDuplicatesWithinK(arr, k);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends