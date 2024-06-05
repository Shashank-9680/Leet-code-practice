class Solution {
    int count(vector<int>nums,int goal){
        int n = nums.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        int count = 0;
       if(goal<0){
           return 0;
       } 
        while (j < n) {
            sum=sum+ nums[j];
            
            while (sum > goal) {
                sum =sum- nums[i];
                i++;
            }
            
            count =count+ (j - i + 1);
            j++;
        }
        
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
//         unordered_map<int, int> prefixSumCount;
//         int currentSum = 0;
//         int count = 0;

//         prefixSumCount[0] = 1;  

//         for (int num : nums) {
//             currentSum += num;
//             if (prefixSumCount.find(currentSum - goal) != prefixSumCount.end()) {
//                 count += prefixSumCount[currentSum - goal];
//             }
//             prefixSumCount[currentSum]++;
//         }

//         return count;
//         }
        
    int count1=count(nums,goal);
        int count2=count(nums,goal-1);
        return count1-count2;
    }
};