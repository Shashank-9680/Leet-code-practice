

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int>ans;
        int n=arr.size();
        ans.push_back(arr[n-1]);
        int maxi=arr[n-1];
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=maxi){
                ans.push_back(arr[i]);
                maxi=arr[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};