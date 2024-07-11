class Solution {
   
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        // Add all initially rotten oranges to the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool hasRotten = false;

            for (int i = 0; i < size; i++) {
                pair<int, int> it = q.front();
                int row = it.first;
                int col = it.second;
                q.pop();

                for (auto d : dir) {
                    int nrow = row + d.first;
                    int ncol = col + d.second;

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                        grid[nrow][ncol] = 2;
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                        hasRotten = true;
                    }
                }
            }

            if (hasRotten) {
                time++;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        
        return time;
    }
};