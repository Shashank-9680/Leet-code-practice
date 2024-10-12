//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

  
   class Solution
{
     long long int f(string s,int k){
         vector<int>freq(26,0);
        int i=0;
        int j=0;
        long long int ans=0;
             int count=0;
        while(j<s.size()){

                  freq[s[j]-'a']++;
             if(freq[s[j]-'a']==1){
                 count++;
             }
               while(count>k){
                 freq[s[i]-'a']--;
                if(freq[s[i]-'a']==0){
                   count--;
                }
                i++;
                
            }
           
            ans+=(j-i+1);
            j++;
            
        }
        
        return ans;
    
        
    }
    
  public:
    long long int substrCount (string s, int k) {
      return f(s,k)-f(s,k-1);
    }
};


//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends