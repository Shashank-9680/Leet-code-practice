class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string ans="";
        int index=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
            }
            else if(s[i]==')'){
                count--;
                if(count==0){
                    ans+=s.substr(index+1,i-index-1);
                    index=i+1;
                }
            }
        }
        return ans;
    }
};