class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
       
        int n=arr.size();
         vector<int>nextSmaller(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&st.top()>=arr[i]){
                st.pop();
            }
            if(st.empty()) nextSmaller[i]=-1;
            else nextSmaller[i]=st.top();
            st.push(arr[i]);
        }
        return nextSmaller;
    }
};