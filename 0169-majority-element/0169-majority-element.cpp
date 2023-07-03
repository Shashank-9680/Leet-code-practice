class Solution {
public:
    int majorityElement(vector<int>& nums) {
         int n = nums.size();
       int a;
       unordered_map<int, int> M;
         for(auto &it:nums)
        { M[it]++;
            
        }
        for (auto &it : M)
        {
            if (it.second > n / 2)
            {
               a=it.first;
                break;
            };
        }
       return a; 
    }
};