class Solution {
    // Recursive function to generate subsets and count those with max OR
    void find(int i, vector<int>& nums, int currentOR, int& count, int maxi) {
      
        if (i == nums.size()) {
            if (currentOR == maxi) {
                count++;
            }
            return;
        }
        
        // Include the current element in the subset OR
        find(i + 1, nums, currentOR | nums[i], count, maxi);
        
        // Exclude the current element from the subset
        find(i + 1, nums, currentOR, count, maxi);
    }
    
public:
    int countMaxOrSubsets(vector<int>& nums) {
        // Calculate the maximum OR by OR-ing all numbers together
        int maxi = 0;
        for (int num : nums) {
            maxi |= num;
        }
        
        int count = 0;
        // Start recursive subset generation
        find(0, nums, 0, count, maxi);
        
        return count;
    }
};
