//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    double power(double b, int e) {
        // code here
        int n = e;    
       double ans = 1.0;
       
       if(n < 0) n = n * -1;
       
       while(n > 0){
        
        if(n % 2 == 1){
            ans *= b;
            n--;
        }else{
            b = b * b;
            n = n/2;
        }  
       }
       
       return (e < 0) ? 1/ans : ans;
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends