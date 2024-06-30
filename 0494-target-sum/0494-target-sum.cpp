class Solution {
    int solve(int ind,int target,vector<int> &nums,map<pair<int,int>,int> &dp)
{
   
    
    if(ind < 0)
    {
        //either you achieve the target or you don't achieve the target
        if(target == 0)
            return 1;
        else
            return 0; 
    }
    if(dp.find({ind, target}) != dp.end())
    {
        return dp[{ind,target}];
    }
    int plus = 0;
    int minus = 0;
    plus = solve(ind-1,target + nums[ind],nums,dp);
    minus = solve(ind - 1, target - nums[ind],nums,dp);

    return dp[{ind, target}]  = plus + minus;
    

}
public:
    int findTargetSumWays(vector<int>& arr, int d) {
          map<pair<int,int>,int> dp;
        return solve(arr.size()-1,d,arr,dp);
    }
};