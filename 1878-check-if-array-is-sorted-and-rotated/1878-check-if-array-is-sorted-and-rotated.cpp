class Solution {
public:
    bool check(vector<int>& nums) {
      int count=0;
        int n=nums.size();
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                count++;
            }
        }
        if(count==0){
            return true;
        }
        if(count>1){
            return false;
        }
        if(count==1){
            if(nums[0]>=nums[n-1]){
                return true;
            }
        }
        return false;
    }
};