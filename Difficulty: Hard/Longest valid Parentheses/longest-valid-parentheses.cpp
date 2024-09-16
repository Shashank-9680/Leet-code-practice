//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string& str) {
       int length=0;
       stack<pair<char,int>>st;
       for(int i=0;i<str.size();i++){
         if(!st.empty()){
             if(str[i]==')'&&st.top().first=='('){
                 st.pop();
                 if(st.empty()){
                length=max(length,i+1);
                 }
                 else{
                 length=max(length,i-st.top().second);    
                 }
                 continue;
                 
             }
         }
             st.push({str[i],i}); 
       
        
       }
       return length;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends