class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i;
        for (i=0;i<nums.size();i++){
            if(i>0){
                if(nums[i]==nums[i-1]){
                   break; 
                   
                }
            }
          
        }
       return nums[i];  
    };    
    
};