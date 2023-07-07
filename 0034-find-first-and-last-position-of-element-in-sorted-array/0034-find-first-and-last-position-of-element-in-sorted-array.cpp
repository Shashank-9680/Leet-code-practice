class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
          auto no1= lower_bound(nums.begin(),nums.end(),target) ;
        auto no2=lower_bound(nums.begin(),nums.end(),target+1);
        
        int index1= no1-nums.begin();
        
           int index2= no2-nums.begin()-1;
        if(index1>=nums.size()||nums[index1]!=target){
            return {-1,-1};
        }
        else{
            return {index1,index2};
        }
    }
};