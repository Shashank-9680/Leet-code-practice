class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int n = rows * cols;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> ans(n, vector<int>(2));
        ans[0] = {rStart, cStart};
        
        int count = 1;
        int step = 1;
        int dirIndex = 0;

        while (count < n) {
            for (int i = 0; i < 2; i++) {  // two iterations for each step size
                int rowMove = directions[dirIndex%4][0];
                int colMove = directions[dirIndex%4][1];
                for (int j = 0; j < step; j++) {
                    rStart += rowMove;
                    cStart += colMove;
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        ans[count] = {rStart, cStart};
                        count++;
                    }
                }
                dirIndex++;  // move to the next direction
            }
            step++;  // increase the step size after every two directions
        }

        return ans;
    }
};