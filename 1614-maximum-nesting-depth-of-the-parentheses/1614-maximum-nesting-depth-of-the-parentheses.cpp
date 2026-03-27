class Solution {
public:
    int maxDepth(string s) {
        int open=0;
        int close=0;
        int maxi=0;
        int count=0;
        for(int i=0;i<s.size();i++){
           if(s[i]=='('){
            open++;
            count++;
           }
           if(s[i]==')'){
              open--;
              maxi=max(count,maxi);
              count--;
            
           }
        }
        return maxi;
    }
};