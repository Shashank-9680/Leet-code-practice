class Solution {

    void findNextRightsSmaller(vector<int>&heights,vector<int>&rightSmaller,int n){
        stack<pair<int,int>>st;
        for(int i=n-1;i>=0;i--){
           while(!st.empty()&& st.top().first>=heights[i]){
             st.pop();
           }
          
           if(st.empty()) rightSmaller[i]=n;
           else rightSmaller[i]= st.top().second;
           
           st.push({heights[i],i});
        }
    }

     void findPrevLeftSmaller(vector<int>&heights,vector<int>&leftSmaller,int n){
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++){
           while(!st.empty()&&st.top().first>heights[i]){
             st.pop();
           }
          
           if(st.empty()) leftSmaller[i]=-1;
           else leftSmaller[i]= st.top().second;
           
           st.push({heights[i],i});
        }
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>rightSmaller(n);
        vector<int>leftSmaller(n);
        findNextRightsSmaller(heights,rightSmaller,n);
        findPrevLeftSmaller(heights,leftSmaller,n);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            int leftCount= i-leftSmaller[i]-1;
            int rightCount=rightSmaller[i]-i;
            int total=leftCount+rightCount;
            maxi=max(heights[i]*total,maxi);
        }
        return maxi;
    }
};