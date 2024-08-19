//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool isSubsequence(int l, int r, string& str1, string& str2) {
        string s = str1.substr(l, r-l+1);
        int cnt = 0;
        int i = 0, j = 0;
        
        while (i < s.length() && j < str2.length()) {
            if (s[i] == str2[j]) {
                j++;
            }
            i++;
        }
        return (j == str2.length());
        
    }
    string minWindow(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int l = 0, r = 0;
        int minLen = n + 1;
        string ans;
        int minL = 0;
        while (r < n) {
          while (isSubsequence(l, r, str1, str2) && l < n) {
              if (minLen > (r-l+1)) {
                  minLen = r-l+1;
                  minL = l;
              }
              l++;
          }
          r++;
        }
        if (minLen == n + 1) return "";
        return str1.substr(minL, minLen);
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends