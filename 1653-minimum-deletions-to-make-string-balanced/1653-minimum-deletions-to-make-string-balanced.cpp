class Solution {
public:
    int minimumDeletions(string s) {
       stack<char>st;
        int n=s.size();
        int i=0;
        int count=0;
       while(i<n){
           if(s[i]=='b'){
               st.push(s[i]);
           }
           else{
               if(!st.empty()&&st.top()!=-1){
                   count++;
                   st.pop();
               }
           }
           i++;
       }
        return count;
    }
};