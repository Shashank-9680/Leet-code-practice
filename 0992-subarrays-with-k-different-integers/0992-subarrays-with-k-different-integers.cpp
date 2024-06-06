class Solution {
    int count(vector<int>nums,int k){
        int count=0;
        map<int,int>m;
        int n=nums.size();
        int i=0;
        int j=0;
        while(j<n){
            m[nums[j]]++;
            while(m.size()>k){
                m[nums[i]]--;
                if(m[nums[i]]==0){
                    m.erase(nums[i]);      
                }
                i++;
            }
           count=count+j-i+1;
            j++;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
    int count1=count(nums,k);
        int count2=count(nums,k-1);
        return count1-count2;
    }
};