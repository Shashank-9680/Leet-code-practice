//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
       int n = arr.size();
        stack<int> leftStack, rightStack;
        int maxDiff = 0;

        // Calculate left smaller elements
        vector<int> leftSmall(n);
        for (int i = 0; i < n; i++) {
            while (!leftStack.empty() && leftStack.top() >= arr[i]) {
                leftStack.pop();
            }
            leftSmall[i] = leftStack.empty() ? 0 : leftStack.top();
            leftStack.push(arr[i]);
        }

        // Calculate right smaller elements and find maximum difference
        for (int i = n - 1; i >= 0; i--) {
            while (!rightStack.empty() && rightStack.top() >= arr[i]) {
                rightStack.pop();
            }
            int rightSmall = rightStack.empty() ? 0 : rightStack.top();
            maxDiff = max(maxDiff, abs(leftSmall[i] - rightSmall));
            rightStack.push(arr[i]);
        }

        return maxDiff;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends