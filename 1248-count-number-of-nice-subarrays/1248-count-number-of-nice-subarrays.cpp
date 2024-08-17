class Solution {
    int subArray1(vector<int>&nums,int goal){
        
        int i=0,j=0;
        int count=0;
        int oddCount=0;
        while(j<nums.size()){
           if(nums[j]%2==1){
               oddCount++;
           }
            while(oddCount>goal){
                if(nums[i]%2==1){
                    oddCount--;
                }
                i++;
            }
            count+=j-i+1;
            j++;
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count1=subArray1(nums,k);
        int count2=subArray1(nums,k-1);
        return abs(count1-count2);
    }
};