//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    static bool comp(pair<int,int>p1,pair<int,int>p2){
        
         if(p1.second==p2.second){
            return p1.first<p2.first; 
        }
        return p1.second>p2.second;
    }
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
      unordered_map<int,int>m;
      for(auto it:arr){
          m[it]++;
      }
      vector<pair<int,int>>v;
      for(auto it:m){
          v.push_back({it.first,it.second});
      }
      sort(v.begin(),v.end(),comp);
      vector<int>result;
      for(auto it:v){
          while(it.second!=0){
              result.push_back(it.first);
              it.second--;
          }
      }
      return result;
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
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends