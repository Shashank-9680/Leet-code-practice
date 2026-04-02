class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto it:s){
            if(it=='('){
                st.push('(');
            }
            if(it=='{'){
                 st.push('{');
            }
            if(it=='['){
                 st.push('[');
            }
            if(it==')'){
                if(!st.empty()&&st.top()=='('){
                    st.pop();
                }
                else{
                  return false;
                }
               
            }
            if(it=='}'){
                if(!st.empty()&&st.top()=='{'){
                    st.pop();
                }
                else{
                  return false;
                }
                
            }
            if(it==']'){
                if(!st.empty()&&st.top()=='['){
                    st.pop();
                }
                else{
                    return false;
                }
            }


        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};