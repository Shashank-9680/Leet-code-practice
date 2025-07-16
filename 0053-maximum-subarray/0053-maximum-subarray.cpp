class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int ans=0;
       int val=INT_MIN;
       for(int i=0;i<nums.size();i++){ 
         ans=ans+nums[i];
        val=max(val,ans);

          if(ans<0){
            ans=0;
          }
       }
       return val;
    }
    
};