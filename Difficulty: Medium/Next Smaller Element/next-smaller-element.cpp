class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& nums2) {
        //  code here
        int n=nums2.size();
        vector<int>prev(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
           while(!st.empty()&&st.top()>=nums2[i]){
            st.pop();
           }
           if(st.empty()) prev[i]=-1;
           else prev[i]=st.top();
           st.push(nums2[i]);
        }
     return prev;

    }
};