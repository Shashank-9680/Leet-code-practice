class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
       int a=0;
        int  n=nums.size();
        for(int i=0;i<n;i++){
            if(abs(nums[i]-i)>1){
             a=1;   
            }
        }
        if(a==1){
            return false;
        }
        else{
            return true;
        }
    }
};