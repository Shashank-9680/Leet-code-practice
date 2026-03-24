class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int count =0;
        int index=0;
         for(int i=0;i<s.size();i++){
              if(s[i]=='('){
                count++;
              }
              if(s[i]==')'){
                count--;
              }
              if(count==0){
                ans+=s.substr(index+1,i-index-1);
                index=i+1;
              }
         }
         return ans;
    }
};