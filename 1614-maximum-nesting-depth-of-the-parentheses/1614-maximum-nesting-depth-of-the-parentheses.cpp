class Solution {
public:
    int maxDepth(string s) {
       int ans=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
                ans=max(count,ans);
            }
            else if(s[i]==')'){
                count--;
                ans=max(count,ans);
            }
        }
        return ans;
    }
};