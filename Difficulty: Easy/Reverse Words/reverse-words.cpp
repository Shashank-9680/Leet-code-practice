//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
     vector<string>words;
     string s="";
     for(int i=0;i<str.size();i++){
        if(str[i]=='.'){
            words.push_back(s);
            s="";
        }
        else{
          s+=str[i];    
        }
      
     }
     words.push_back(s);
     s="";
     int n=words.size();
    reverse(words.begin(),words.end());
    string ans="";
    for(int i=0;i<n-1;i++){
        ans+=words[i];
        ans+=".";
    }
    ans+=words[n-1];
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends