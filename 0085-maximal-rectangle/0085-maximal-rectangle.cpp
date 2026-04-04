class Solution {
public:

    void findNextRightsSmaller(vector<int>& heights, vector<int>& rightSmaller, int n){
        stack<pair<int,int>> st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && st.top().first >= heights[i]){
                st.pop();
            }
            rightSmaller[i] = st.empty() ? n : st.top().second;
            st.push({heights[i], i});
        }
    }

    void findPrevLeftSmaller(vector<int>& heights, vector<int>& leftSmaller, int n){
        stack<pair<int,int>> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top().first > heights[i]){ // FIXED (>=)
                st.pop();
            }
            leftSmaller[i] = st.empty() ? -1 : st.top().second;
            st.push({heights[i], i});
        }
    }

    int largestRectangleArea(vector<int> heights) {
        int n = heights.size();
        vector<int> rightSmaller(n), leftSmaller(n);

        findNextRightsSmaller(heights, rightSmaller, n);
        findPrevLeftSmaller(heights, leftSmaller, n);

        int maxi = 0;

        for(int i = 0; i < n; i++){
             int leftCount= i-leftSmaller[i]-1;
            int rightCount=rightSmaller[i]-i;
            int total=leftCount+rightCount;
            maxi=max(heights[i]*total,maxi);
        }

        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
         // Return 0 if matrix is empty
        if (matrix.empty()) return 0;

        // Get number of columns
        int m = matrix[0].size();

        vector<int> height(m, 0);

        int maxArea = 0;

        for (auto& row : matrix) {

            for (int i = 0; i < m; i++) {
                if (row[i] == '1') height[i]++;
                else height[i] = 0;
            }
            maxArea = max(maxArea, largestRectangleArea(height));
        }
    return maxArea;
    }
};