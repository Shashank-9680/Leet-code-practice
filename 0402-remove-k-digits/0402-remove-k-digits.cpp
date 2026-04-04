class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int count=0;
    
        for(int i=0;i<num.size();i++){
            while(!st.empty()&&st.top()>num[i]){
                if(count==k) break;
                count++;
                st.pop();
            }
            st.push(num[i]);
        }

        while(count!=k){
            count++;
            st.pop();
        }

        string str="";
        if(st.empty()) return "0";
        
        while(!st.empty()){
            str+=st.top();
            st.pop();
        }

        reverse(str.begin(),str.end());
        bool val=false;
        for(int i=0;i<str.size();i++){
            if(str[i]!='0'){
                val=true;
            }
        }
        if(!val) return "0";
        int i=0;

        while(i<str.size()){
            if(str[i]!='0'){
               break;
            }
           
          i++;
            
        }
        return str.substr(i,str.size()-i);


    }
};