class Solution {
    int subArray1(vector<int>&nums,int k){
      unordered_map<int,int>m;
   int i=0;
   int j=0;
   int n=nums.size();
   int count=0;
   while(j<n){
     m[nums[j]]++;
     while(m.size()>k){
        m[nums[i]]--;
        if(m[nums[i]]==0){
            m.erase(nums[i]);
        }
       
        i++;
      }
     count+=(j-i+1);
      j++;
     
   }
   return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int count1=subArray1(nums,k);
        int count2=subArray1(nums,k-1);
        return abs(count1-count2);
    }
};