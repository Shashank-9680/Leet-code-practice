//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
      int n = arr.size();
        
        
        if (n <= 1) return 0;
        
       
        if (arr[0] == 0) return -1;

        int r = 0;     
        int l = 0;     
        int jumps = 0; 
        
        while (r < n - 1) {
            int farthest = 0; 
            bool canMove = false;
            
            // Find the farthest index we can reach in the current jump
            for (int i = l; i <= r; i++) {
                if (arr[i] != 0) {
                    canMove = true;
                }
                farthest = max(farthest, arr[i] + i);
            }
            
            // If no progress can be made, return -1
            if (!canMove) return -1;
            
            // Move to the next range
            l = r + 1;
            r = farthest;
            jumps++;
            
            // If the farthest we can reach is already beyond or at the last index
            if (r >= n - 1) return jumps;
        }
        
        return jumps;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends