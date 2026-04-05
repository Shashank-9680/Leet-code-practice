class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>nums2=nums;
        for(auto it:nums){
           nums2.push_back(it);
        }
        int n=nums2.size();
        vector<int>next(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
           while(!st.empty()&&st.top()<=nums2[i]){
            st.pop();
           }
           if(st.empty()) next[i]=-1;
           else next[i]=st.top();
           st.push(nums2[i]);
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(next[i]);
        }
        return ans;
    }
};