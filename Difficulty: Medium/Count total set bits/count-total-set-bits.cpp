//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
     int find(int n){
        int x=0;
        while((1<<x)<=n){
            x++;
        }
        return x-1;
    }
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        if(n==0){
            return 0;
        }
        int x=find(n);
        int first=x*(1<<(x-1));
        int second=n-(1<<x)+1;
        int third=n-(1<<x);
        int ans= first+second+countSetBits(third);
        return ans;
    }
   
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends