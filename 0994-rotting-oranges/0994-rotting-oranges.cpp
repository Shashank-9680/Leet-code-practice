class Solution {
   
public:
    int orangesRotting(vector<vector<int>>& grid) {
         int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int, int>> q;

        // Push all initially rotten oranges into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j]=1;
                }
            }
        }

        // Directions array to traverse up, left, down, right
        vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int time = 0;

        // BFS to process all rotten oranges level by level (minute by minute)
        while (!q.empty()) {
            int size = q.size();
            bool isRotten = false;
            for (int i = 0; i < size; i++) {
                auto it = q.front();
                q.pop();
                int row = it.first;
                int col = it.second;

                for (auto d : dir) {
                    int nrow = row + d.first;
                    int ncol = col + d.second;
                    // If adjacent cell is a fresh orange, rot it and push it into the queue
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1&&!vis[nrow][ncol]) {
                        grid[nrow][ncol] = 2;
                        q.push({nrow, ncol});
                        isRotten = true;
                        vis[nrow][ncol]=1;
                    }
                }
            }
            if (isRotten) {
                time++;
            }
        }

        // Check if there are any fresh oranges left
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