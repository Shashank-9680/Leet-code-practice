class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> result(m, vector<int>(n, -1));
        int top = 0, left = 0;
        int right = n - 1, bottom = m - 1;
        
        while (top <= bottom && left <= right) {
            // Traverse from left to right on the top row
            for (int i = left; i <= right && head != nullptr; i++) {
                result[top][i] = head->val;
                head = head->next;
            }
            top++;
            
            // Traverse from top to bottom on the right column
            for (int i = top; i <= bottom && head != nullptr; i++) {
                result[i][right] = head->val;
                head = head->next;
            }
            right--;
            
            // Traverse from right to left on the bottom row, if still valid
            if (top <= bottom) {
                for (int i = right; i >= left && head != nullptr; i--) {
                    result[bottom][i] = head->val;
                    head = head->next;
                }
                bottom--;
            }
            
            // Traverse from bottom to top on the left column, if still valid
            if (left <= right) {
                for (int i = bottom; i >= top && head != nullptr; i--) {
                    result[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }
        }
        
        return result;
    }
};
