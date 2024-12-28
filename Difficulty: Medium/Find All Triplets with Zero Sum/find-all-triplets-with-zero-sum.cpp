//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
     vector<vector<int>>ans;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        for(int i=0;i<=arr.size()-3;i++){
            int no1=arr[i];
            for(int j=i+1;j<arr.size();j++){
                int sum=no1+arr[j];
                int rem=0-sum;
                if(mp.find(rem)!=mp.end()){
                    for(int k=0;k<mp[rem].size();k++){
                        if(mp[rem][k]>j && mp[rem][k]!=j){
                            vector<int>a;
                            a.push_back(i);
                            a.push_back(j);
                            a.push_back(mp[rem][k]);
                            sort(a.begin(),a.end());
                            ans.push_back(a);
                        }
                        
                    }
                }
                
            }
            
        }
        return ans;
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
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends