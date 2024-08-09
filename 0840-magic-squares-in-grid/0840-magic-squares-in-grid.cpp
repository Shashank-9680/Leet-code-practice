class Solution {
    void getSum(const vector<int>& v, vector<int>& sumVec) {
        int sum = 0;
        for (int i = 0; i < v.size(); i++) {
            sum += v[i];
        }
        sumVec.push_back(sum);
    }

    bool isDistinct(const vector<vector<int>>& v) {
        vector<int> hash(10, 0);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (v[i][j] < 1 || v[i][j] > 9) {
                    return false;  
                }
                hash[v[i][j]]++;
            }
        }
        for (int i = 1; i < 10; i++) {
            if (hash[i] != 1) {
                return false;
            }
        }
        return true;
    }

    bool magicSquare(const vector<vector<int>>& v) {
        vector<int> rowSums, colSums;
        int dSum1 = 0, dSum2 = 0;
        
        for (int i = 0; i < 3; i++) {
            getSum(v[i], rowSums);
            dSum1 += v[i][i];
            dSum2 += v[i][2 - i];
        }
        
        for (int j = 0; j < 3; j++) {
            vector<int> col;
            for (int i = 0; i < 3; i++) {
                col.push_back(v[i][j]);
            }
            getSum(col, colSums);
        }

        if (!isDistinct(v)) {
            return false;
        }

        if (rowSums[0] != colSums[0] || rowSums[0] != dSum1 || rowSums[0] != dSum2) {
            return false;
        }

        for (int i = 1; i < 3; i++) {
            if (rowSums[i] != rowSums[0] || colSums[i] != colSums[0]) {
                return false;
            }
        }

        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (n < 3 || m < 3) {
            return 0;
        }
        int count = 0;

        for (int row = 0; row <= n - 3; ++row) {
            for (int col = 0; col <= m - 3; ++col) {
                vector<vector<int>> v(3, vector<int>(3));
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        v[i][j] = grid[row + i][col + j];
                    }
                }
                if (magicSquare(v)) {
                    count++;
                }
            }
        }
        return count;
    }
};
