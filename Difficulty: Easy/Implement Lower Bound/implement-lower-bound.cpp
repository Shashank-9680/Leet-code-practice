class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        if(arr[n-1]<target){
            return n;
        }
        int low=0;
        int high=n-1;
        int ans=7;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]<target){
                low=mid+1;
            }
            else{
               ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};
