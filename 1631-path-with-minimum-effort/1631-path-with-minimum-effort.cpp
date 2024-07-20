class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        // Vector to store the minimum effort to reach each cell
        vector<vector<int>> v(n, vector<int>(m, INT_MAX));
        v[0][0] = 0;

        // Priority queue to store (effort, (row, col))
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        q.push({0, {0, 0}});
        
        // Directions array to move in 4 directions
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int weight = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();

           

            for (auto it : directions) {
                int nrow = row + it.first;
                int ncol = col + it.second;
                
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int effort = max(weight, abs(heights[nrow][ncol] - heights[row][col]));
                    if (effort < v[nrow][ncol]) {
                        v[nrow][ncol] = effort;
                        q.push({effort, {nrow, ncol}});
                    }
                }
            }
        }
        
        return v[n-1][m-1];
    }
};