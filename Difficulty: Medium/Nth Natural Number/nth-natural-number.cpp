//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    // bool check(long long int n){
    //     while(n>0){
    //         long long int a=n%10;
    //         if(a==9){
    //             return true;
    //         }
    //         n=n/10;
    //     }
    //     return false;
    // }
    // // c2=1 
  public:
    long long findNth(long long n) {
    //     long long int count1=1;
    //     long long int count2=0;
    //   while(count2!=n){
    //       if(!check(count1)){
    //           count2++;
    //       }
    //       count1++;
    //   }
    //   return count1-1;
     long long result = 0;
        long long multiplier = 1;
        
        // Convert the number `n` to its equivalent in base-9
        while (n > 0) {
            result += (n % 9) * multiplier; // Get the last digit in base-9 and add to result
            n /= 9; // Reduce the number for next digit
            multiplier *= 10; // Shift left in decimal for the next base-9 digit
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, ans;
        cin >> n;
        Solution obj;
        ans = obj.findNth(n);
        cout << ans << endl;
    }
}

// } Driver Code Ends