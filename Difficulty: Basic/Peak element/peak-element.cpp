//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int peakElement(vector<int> &arr) {
          int n = arr.size();

 

        // Handle edge case: single-element array

        if (n == 1) return 0;

 

        // Loop through the array to find a peak element

        for (int i = 0; i < n; i++) {

            if (i == 0) {

                // Check if the first element is a peak

                if (arr[0] >= arr[1]) return i;

            } else if (i == n - 1) {

                // Check if the last element is a peak

                if (arr[n - 1] >= arr[n - 2]) return i;

            } else {

                // Check if the current element is greater than or equal to neighbors

                if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1]) return i;

            }

        }

 

        return -1; // This line will never execute if the input guarantees at least one peak
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int idx = ob.peakElement(a);
        int n = a.size();
        bool f = 0;
        if (idx < 0 and idx >= n)
            cout << "false" << endl;
        else {
            if (n == 1 and idx == 0)
                f = 1;
            else if (idx == 0 and a[0] > a[1])
                f = 1;
            else if (idx == n - 1 and a[n - 1] > a[n - 2])
                f = 1;
            else if (a[idx] > a[idx + 1] and a[idx] > a[idx - 1])
                f = 1;
            else
                f = 0;
            if (f)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends