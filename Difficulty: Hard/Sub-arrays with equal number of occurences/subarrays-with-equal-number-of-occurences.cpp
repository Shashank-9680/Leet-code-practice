//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
     unordered_map<int,int>m;
     int c_x=0;
     int c_y=0;
     int count=0;
     m[0]=1;
     for(auto it:arr){
        if(it==x){
            c_x++;
        } 
         if(it==y){
            c_y++;
        }
        if(m.find(c_x-c_y)!=m.end()){
           count+=m[c_x-c_y];
        }
        m[c_x-c_y]++;
     }
    return count;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int x = stoi(ks);
        string ks1;
        getline(cin, ks1);
        int y = stoi(ks1);
        Solution ob;
        int ans = ob.sameOccurrence(arr, x, y);
        cout << ans << "\n";
        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends