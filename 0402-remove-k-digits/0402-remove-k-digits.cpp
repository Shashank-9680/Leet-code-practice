class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        string ans="";
        int count=0;
        for(int i=0;i<num.size();i++){
            while(!st.empty()&&st.top()>num[i]){
                if(count==k) break;
                st.pop();
                count++;
            }
            st.push(num[i]);
        }

        while(!st.empty()&&count!=k){
            st.pop();
            count++;
        }

        if(st.empty()) return "0";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        bool val=false;
        for(auto it:ans){
            if(it!='0'){
                val=true;
            }
        }
        int n=ans.size();
        if(!val) return "0";
        int i=0;
        while(i<n){
            if(ans[i]!='0'){
                break;
            }
            i++;
        }
        return ans.substr(i,n-i);
    }
};