class Solution {
    bool boolean(int i,int j,string &p,string &s,vector<vector<int>>&dp ){
        if(i<0&&j<0) return true;
        if(i<0&&j>=0) return false;
       
        if(j<0&&i>=0){
            for(int ii=0;ii<=i;ii++){
                if(p[ii]!='*'){
                    return false;
                }
            }
            return true;
        }
         if(dp[i][j]!=-1) return dp[i][j];
        if(p[i]==s[j]||p[i]=='?'){
            return dp[i][j]=boolean(i-1,j-1,p,s,dp);
        }
        if(p[i]=='*'){
            return dp[i][j]= boolean(i,j-1,p,s,dp)|boolean(i-1,j,p,s,dp);
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return boolean(n-1,m-1,p,s,dp);
    }
};