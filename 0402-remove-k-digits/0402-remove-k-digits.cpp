class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<char>st;
     string result;
      for(int i=0;i<nums.size();i++){
            while(!st.empty()&&nums[i]<st.top()&&k>0){
                st.pop();
                k--;
            }
            if(!st.empty()||nums[i]!='0'){
              st.push(nums[i]);
            }
         
        
            
        }
          while (!st.empty() && k > 0) {
            st.pop();
            k--;
        } 
        
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
       
     return result.empty() ? "0" : result;
    }
};