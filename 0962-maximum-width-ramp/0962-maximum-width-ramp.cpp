class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
      stack<int>st;
        for(int i=0;i<nums.size();i++){
         if(st.empty()||nums[st.top()]>nums[i]){
             st.push(i);
         }
        }
        int maxi=0;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]<=nums[i]){
                maxi=max(i-st.top(),maxi);
                st.pop();
            }
        }
       return maxi;
    }
};