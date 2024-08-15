class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        
       
        int left = 0, right = nums.back() - nums.front();
        int ans=-1;
        
        while (left <=right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            int j = 1;
           
            
           
           for(int i=0;i<n;i++){
               while(j<n&&nums[j]-nums[i]<=mid){
                   j++;
               }
              
               count+=j-i-1;
           }
            
            
            if (count >=k) {
                 ans=mid;
                right = mid-1;
            } else {
               
                left = mid + 1;
            }
        }
        
        return ans;
    }
};
