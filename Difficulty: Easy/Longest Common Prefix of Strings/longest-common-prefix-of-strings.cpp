//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        int n=arr.size();
       sort(arr.begin(),arr.end());
       string a=arr[0];
       string b=arr[n-1];
       string s="";
       int i=0;
       while(i<a.size()){
           if(a[i]==b[i]){
               s+=a[i];
           }
           else{
               break;
           }
           i++;
       }
       if(s.size()==0){
           return "-1";
       }
       return s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends