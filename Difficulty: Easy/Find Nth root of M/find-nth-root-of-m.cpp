//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    long long power(int base, int exp) {
        long long result = 1;
        for (int i = 0; i < exp; ++i) {
            result *= base;
            if (result > INT_MAX) {
                return INT_MAX; // To prevent overflow
            }
        }
        return result;
    }
	public:
	int NthRoot(int n, int m)
	{
	    int low=1;
	    int high=m;
	    int ans=-1;
	    while(low<=high){
	        int mid=(low+high)/2;
	        if(power(mid,n)==m){
	            return mid;
	        }
	        else if(power(mid,n)<m){
	           
	            low=mid+1;
	        }
	        else{
	            high=mid-1;
	        }
	    }
	    return -1;
	}  
};


// } Driver Code Ends

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends