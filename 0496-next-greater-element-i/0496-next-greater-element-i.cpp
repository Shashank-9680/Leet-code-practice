class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
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

        for(auto it:next){
            cout<<it;
        }

        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums2[i]]=i;
        }
        vector<int>ans;
        for(auto it:nums1){
           ans.push_back(next[m[it]]);
        }
        return ans;
    }
};