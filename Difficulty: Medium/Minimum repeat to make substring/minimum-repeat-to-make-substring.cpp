//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
      string s = "";
        int count = 0;
        
       
        while (s.size() < s2.size()) {
            s += s1;
            count++;
        }
        
        // Check if s2 is now a substring of s
        if (s.find(s2) != string::npos) {
            return count;
        }
        
        // Append s1 one more time to handle edge cases
        s += s1;
        count++;
        
        // Check again if s2 is now a substring of s
        if (s.find(s2) != string::npos) {
            return count;
        }
        
        // If s2 is still not a substring, return -1
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends