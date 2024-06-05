class Solution {
    int count(vector<int>nums,int k){
          int i=0;
        int j=0;
        int oddcount=0;
        int count=0;
        int n=nums.size();
       
        while(j<n){
          if(nums[j]%2!=0){
              oddcount++;
          }
        while(oddcount>k){
                if(nums[i]%2!=0) oddcount--;
                i++;
            }
            count=count+j-i+1;
            j++;
        }
            return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
     int count1=count(nums,k);
        int count2=count(nums,k-1);
        return count1-count2;
        
    }
};