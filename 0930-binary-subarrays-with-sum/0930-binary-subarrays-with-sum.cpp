class Solution {
   int subArray1(vector<int>nums,int goal){
       if(goal<0){
           return 0;
       }
       int i=0;
       int j=0;
       int count=0;
       int n=nums.size();
       int sum=0;
       while(j<n){
           sum=sum+nums[j];
           while(sum>goal){
               sum=sum-nums[i];
               i++;
           }
           count+=j-i+1;
           j++;
       }
       return count;
   }
    
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count1=subArray1(nums,goal);
        int count2=subArray1(nums,goal-1);
        return abs(count1-count2);
    }
};