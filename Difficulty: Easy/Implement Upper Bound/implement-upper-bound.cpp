class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        int ans=arr.size();
        int low=0;
        int high=n-1;
        while(low<=high){
           int mid=(low+high)/2;
           if(arr[mid]<=target){
               low=mid+1;
           }
           else{
               ans=min(ans,mid);
               high=mid-1;
           }

        }
        return ans;
    }
};
