class Solution {
public:
    bool check(vector<int>& nums) {
      int count=0;
      for(int i=1;i<nums.size();i++){
        if(nums[i-1]>nums[i]){
            count++;
        }
      }
      if(count==0){
         return true;
      }
      if(count ==1){
        if(nums[0]<nums[nums.size()-1]){
            return false;
        }
        else{
            return true;
        }
      }
      return false;;
    }
};

