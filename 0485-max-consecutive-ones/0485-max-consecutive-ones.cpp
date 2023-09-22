class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    int count=0;
        vector<int>v;
        v.push_back(0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
                v.push_back(count);
            }
            else{
                count=0;
            }
        }
        return *max_element(v.begin(), v.end());
    }
};