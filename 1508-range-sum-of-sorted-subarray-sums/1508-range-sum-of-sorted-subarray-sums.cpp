class Solution {
    const int mod=1e9+7;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>v;
        
        for(int i=0;i<n;i++){
            int sum=nums[i];
            v.push_back(sum);
            for(int j=i+1;j<n;j++){
                sum+=nums[j];
                v.push_back(sum);
            }
        }
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=left-1;i<right;i++){
            ans=(ans+v[i])%mod;
        }
        return ans;
    }
};