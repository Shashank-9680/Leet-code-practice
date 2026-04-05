class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int maxi=0;
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                int ns=i;
                int element=st.top();
                st.pop();
                int prev=st.empty()?-1:st.top();
                maxi=max(maxi,((ns-prev-1)*heights[element]));
            }
             st.push(i);
        }

        while(!st.empty()){
            int ns=n;
            int element=st.top();
            st.pop();
            int ps=st.empty()?-1:st.top();
            maxi=max(maxi,((ns-ps-1)*heights[element]));
        }
        return maxi;
    }
};