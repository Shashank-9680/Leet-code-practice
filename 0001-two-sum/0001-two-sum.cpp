class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int n=nums.size();
       for(int i=0;i<n;i++){
         
           auto it=m.find(k-nums[i]);
           if(it!=m.end()){
           return {i,it->second};
           }
            m[nums[i]]=i;
          }
        return {-1,-1};
      
 }
};