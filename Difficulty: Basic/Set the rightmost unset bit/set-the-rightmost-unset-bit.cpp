//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int setBit(int n) {
      int x=0;
      int value=0;
      while((1<<x)<=n){
          x++;
      }
      value=x+1;
    //   if((1<<x)==n){
    //       value=x;
    //   }
    //   else{
    //       value=x+1;
    //   }
      for(int i=0;i<value;i++){
          if((n&(1<<i))==0){
              return n|(1<<i);
          }
      }
      return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends