class Solution {
    int find(int i,vector<int>&dp){
     if(i==0) return 1;
     if(i==1) return 1;
     if(dp[i]!=-1) return dp[i];
     return dp[i]= find(i-1,dp)+find(i-2,dp);
    }
public:
    int climbStairs(int n) {
        // vector<int>dp(n+1,0);
        int prev1=1;
        int prev2=1;
        for(int i=2;i<=n;i++){
            int curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
            
        }

        return prev1; 
    }
};