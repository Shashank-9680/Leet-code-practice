//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<int>a(n);
        int i=0;
        int j=n-1;
        for(int k=0;k<n;k++){
            if(k%2==0){
                a[k]=arr[i];
                i++;
            }else{
                a[k]=arr[j];
                j--;
            }
        }
        long long sum=0;
        for(int i=0;i<n-1;i++){
            sum=sum+abs(a[i]-a[i+1]);
        }
        sum+=abs(a[0]-a[n-1]);
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends