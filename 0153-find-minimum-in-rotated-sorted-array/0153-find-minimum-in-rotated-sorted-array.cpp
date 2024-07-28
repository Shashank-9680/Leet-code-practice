class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        if(arr[n-1]>=arr[0]){
            return arr[0];
        }
        int low=0;
        int high=n-1;
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[low]<=arr[mid]){
              ans=min(arr[low],ans);
                low=mid+1;
            }
            else{
                ans=min(arr[mid],ans);
                high=mid-1;
            }
            
        }
        return ans;
    }
};