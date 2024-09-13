//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
       vector<int>n;  
       vector<int>p; 
       
      
       for(int i = 0; i < arr.size(); i++) {
           if(arr[i] < 0) {
               n.push_back(arr[i]);
           } else {
               p.push_back(arr[i]);
           }
       }

       int i = 0, j = 0;
       int k = 0;

      
       while(k < arr.size() && i < n.size() && j < p.size()) {
           if(k % 2 == 0) {
               arr[k] = p[j]; 
               j++;
           } else {
               arr[k] = n[i]; 
               i++;
           }
           k++;
       }

     
       while(k < arr.size() && j < p.size()) {
           arr[k] = p[j];
           k++;
           j++;
       }

     
       while(k < arr.size() && i < n.size()) {
           arr[k] = n[i];
           k++;
           i++;
       }
     
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends