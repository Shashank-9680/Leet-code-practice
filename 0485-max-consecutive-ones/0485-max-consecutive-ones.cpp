class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       vector<int>v;
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
           if(nums[i]==1){
               count++;
           }
            else{
                v.push_back(count);
                count=0;
            }
            v.push_back(count);
        }
        // auto max=max_element(v.begin(),v.end());
        sort(v.rbegin(),v.rend());
        return v[0];
    }
};