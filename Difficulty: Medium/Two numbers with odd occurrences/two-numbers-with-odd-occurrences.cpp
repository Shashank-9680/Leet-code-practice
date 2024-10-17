//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long xorr=0;
       for(int i=0;i<N;i++){
           xorr=xorr^Arr[i];
       }
       int n=xorr;
       int rightMostBitSet=(n&n-1)^n;
       long long ones=0;
       long long twoes=0;
       for(int i=0;i<N;i++){
           if((Arr[i]&rightMostBitSet)!=0){
               ones=ones^Arr[i];
           }
           else{
               twoes=twoes^Arr[i];
           }
       }
       if(ones>twoes){
           return {ones,twoes};
       }
       return {twoes,ones};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends