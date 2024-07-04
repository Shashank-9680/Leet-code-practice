class Solution {
    int minimum(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
        if(i>j) return 0;
        int mini=1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int ind=i;ind<=j;ind++){
            int steps=cuts[j+1]-cuts[i-1]+minimum(i,ind-1,cuts,dp)+minimum(ind+1,j,cuts,dp);
            mini=min(mini,steps);
        }
        return dp[i][j]=mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int m=cuts.size();
        cuts.push_back(n);
       cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        return minimum(1,m,cuts,dp);
    }
};