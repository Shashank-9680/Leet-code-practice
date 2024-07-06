class Solution {
public:
    int jump(vector<int>& nums) {
       int n=nums.size();
          if (n <= 1) return 0;
        int r=0;
        int l=0;
        int jump=0;
         while (r < n - 1) {
            int farthest = 0;
            for (int i = l; i <= r; i++) {
                farthest = max(farthest, nums[i] + i);
            }
            l = r + 1;
            r = farthest;
            jump++;
        }
        return jump;
    }
};