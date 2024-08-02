class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int countOnes = 0;
        
        // Count the number of 1s in the original array
        for (int num : nums) {
            if (num == 1) {
                countOnes++;
            }
        }
        
        // If there are no 1s or all are 1s, no swaps needed
        if (countOnes == 0 || countOnes == n) {
            return 0;
        }
        
        // Extend the array to simulate the circular array
        nums.insert(nums.end(), nums.begin(), nums.end());
        
        // Use a sliding window (two-pointer) approach
        int countZeroes = 0;
        for (int i = 0; i < countOnes; i++) {
            if (nums[i] == 0) {
                countZeroes++;
            }
        }
        
        int minZeroes = countZeroes;
        int i = 0, j = countOnes;
        
        while (j < nums.size()) {
            if (nums[i] == 0) {
                countZeroes--;
            }
            if (nums[j] == 0) {
                countZeroes++;
            }
            minZeroes = min(minZeroes, countZeroes);
            i++;
            j++;
        }
        
        return minZeroes;
    }
};
