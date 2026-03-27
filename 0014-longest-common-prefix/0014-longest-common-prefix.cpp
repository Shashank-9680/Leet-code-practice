class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        int size=min(strs[0].size(),strs[n-1].size());
        int i=0;
        
        string ans="";
        string temp1=strs[0];
        string temp2=strs[n-1];
        while(i<size){
           if(temp1[i]!=temp2[i]){
            break;
           }
           ans+=temp1[i];
           i++;
        }
        return ans;
    }
};