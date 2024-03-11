class Solution {
public:
    void sortColors(vector<int>& nums) {
       multiset<int>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
      nums.clear();
        for(auto &values:s){
            nums.push_back(values);
        }
    }
};