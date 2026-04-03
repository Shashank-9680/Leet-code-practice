class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>newArray(nums.begin(),nums.end());
        for(auto it:nums){
            newArray.push_back(it);
        }
        stack<int>st;
        int n=newArray.size();
         vector<int>nextGreater(n);
        for(int i=n-1;i>=0;i--){
           while(!st.empty()&& newArray[i]>=st.top()){
            st.pop();
           }

           if(st.empty()) nextGreater[i]=-1;
           else nextGreater[i]= st.top();
           st.push(newArray[i]);
        }
       
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
         ans.push_back(nextGreater[i]);
        }
        return ans;
    }
};