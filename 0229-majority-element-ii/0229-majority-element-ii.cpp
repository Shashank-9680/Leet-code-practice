class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> v;
       unordered_map<int, int> M;
         for(auto &it:nums)
        { M[it]++;
            
        }
        for (auto &it : M)
        {
            if (it.second > n / 3)
            {
                v.push_back(it.first);
            };
        }
        return v;
    }
};