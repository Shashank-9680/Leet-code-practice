//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
      unordered_map<int,int>m;
      int i=0;
      int j=0;
      int n=arr.size();
      int k=2;
      int length=0;
      while(j<n){
          m[arr[j]]++;
          while(m.size()>k){
              m[arr[i]]--;
              if(m[arr[i]]==0){
                  m.erase(arr[i]);
              }
              i++;
          }
          length=max(length,j-i+1);
          j++;
      }
      return length;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends