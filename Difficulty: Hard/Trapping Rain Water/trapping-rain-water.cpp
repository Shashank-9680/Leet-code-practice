//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
         int n=arr.size();
        int max=0;
        for(int i=0;i<n;i++)
        {
            if(arr[max]<arr[i])
            max=i;
        }
        int water=0;
        int left_max=0;
        for(int i=0;i<max;i++)
        {
            if(arr[i]>left_max)
            left_max=arr[i];
            
            water=water+(left_max-arr[i]);
        }
         int right_max=0;
        for(int i=n-1;i>max;i--)
        {
            if(arr[i]>right_max)
            right_max=arr[i];
            water=water+(right_max-arr[i]);
        }
        return water;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends