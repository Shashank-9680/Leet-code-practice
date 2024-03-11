class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
       
        int value=0;
        for(auto &values:m){
          if(values.second>(n/2)){
              value=values.first;
              
          }
        }
       
        return value;
    }
};