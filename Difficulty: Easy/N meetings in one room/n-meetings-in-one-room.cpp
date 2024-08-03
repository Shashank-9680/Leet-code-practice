//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    static bool comp(pair<int,int>p1,pair<int,int>p2){
        return p1.second<p2.second;
    }
  public:
    
    int maxMeetings(int n, int start[], int end[]) {
       vector<pair<int,int>>v;
       for(int i=0;i<n;i++){
           v.push_back({start[i],end[i]});
       }
       sort(v.begin(),v.end(),comp);
       int count=1;
       int initial=v[0].second;
       for(int i=1;i<v.size();i++){
           if(v[i].first>initial){
               count++;
               initial=v[i].second;
           }
       }
       return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends