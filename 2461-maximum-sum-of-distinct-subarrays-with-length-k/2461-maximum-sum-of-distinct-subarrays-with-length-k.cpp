class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long int sum=0;
        int n=nums.size();
      
        unordered_map<int,int>m;
        long long int msum=0;
        for(int i=0;i<k;i++){
            sum=sum+nums[i];
            m[nums[i]]++;
        }
        if(m.size()==k){
            msum=max(msum,sum);
        }
          int i=0;
        int j=k;
        while(j<n){
             cout<<sum;
            sum=sum-nums[i];
           
           m[nums[i]]--;
            if(m[nums[i]]==0){
                m.erase(nums[i]);
            }
            i++;
            sum=sum+nums[j];
            m[nums[j]]++;
             if(m.size()==k){
            msum=max(msum,sum);
            } 
            j++;
            
        }
        return msum;
    }
};