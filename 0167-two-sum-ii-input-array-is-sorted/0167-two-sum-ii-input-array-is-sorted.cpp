class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
        int n=nums.size();
        int high=n-1;
        int low=0;
        vector<int>v;
       while(low<=high){
          
           if(nums[low]+nums[high]==target){
              return {low+1,high+1};
               break;
           }
           else if(nums[low]+nums[high]>target){
               high--;
           }
           else{
               low++;
           }
       }
       return v;
    }
};