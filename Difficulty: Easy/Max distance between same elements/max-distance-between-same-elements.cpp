//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        int n=arr.size();
      
        unordered_map<int,int>m1;
         unordered_map<int,int>m2;
         for(int i=0;i<n;i++){
             if(m1.find(arr[i])==m1.end()){
                 m1[arr[i]]=i;
             }
         }
       for(int i=0;i<n;i++){
           
                 m2[arr[i]]=i;
            
         }
         int maxi=INT_MIN;
         for(int i=0;i<n;i++){
             int d1=m1[arr[i]];
             int d2=m2[arr[i]];
             maxi=max(maxi,abs(d1-d2));
         }
       
      return maxi;
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
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends