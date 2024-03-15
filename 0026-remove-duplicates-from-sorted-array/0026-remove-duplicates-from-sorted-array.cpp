class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
//        set<int>s;
      
//         for(int i=0;i<nums.size();i++){
//             s.insert(nums[i]);
//         }
//           nums.clear();
//         for(auto values:s){
//             nums.push_back(values);
//         }
//         return nums.size();
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[j]!=nums[i]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};