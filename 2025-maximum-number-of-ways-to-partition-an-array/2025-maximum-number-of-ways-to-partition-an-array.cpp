class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        unordered_map<long,int>ml,mr;
        int n=nums.size();
       long long int left=0;
       long long int right=0;
       long long int sum=0;
        for(long long int i=0;i<n;i++){
          sum=sum+nums[i];
        }
        for(int i=0;i<n-1;i++){
            left+=nums[i];
            right=sum-left;
            mr[left-right]++;
        }
        left=0;
        right=0;
        int ans=mr[0];
        for(long long int i=0;i<n;i++){
           long long int d=k-nums[i];
            left+=nums[i];
            ans=max(ans,ml[d]+mr[-d]);
            right=sum-left;
            ml[left-right]++;
            mr[left-right]--;
        }
        return ans;
    }
};