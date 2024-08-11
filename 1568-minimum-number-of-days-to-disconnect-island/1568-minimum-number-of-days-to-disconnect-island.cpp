
class Solution {
      bool isValid(int nrow, int ncol, int n, int m) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m;
    }

    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<pair<int, int>>& directions) {
        visited[i][j] = true;
        int n = grid.size();
        int m = grid[0].size();
        for (auto dir : directions) {
            int nrow = i + dir.first;
            int ncol = j + dir.second;
            if (isValid(nrow, ncol, n, m) && grid[nrow][ncol] == 1 && !visited[nrow][ncol]) {
                dfs(nrow, ncol, grid, visited, directions);
            }
        }
    }
    bool isConnected(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        bool foundLand = false;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    if (foundLand) return false; // More than one island found
                    foundLand = true;
                    dfs(i, j, grid, visited, directions);
                }
            }
        }
        return true;
    }

public:
    int minDays(vector<vector<int>>& grid) {
         int n = grid.size();
        int m = grid[0].size();

       
        if (!isConnected(grid)) return 0;

        
        int landCount = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) landCount++;
            }
        }
        if (landCount == 1) return 1;

       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (!isConnected(grid)) return 1;
                    grid[i][j] = 1; 
                }
            }
        }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(grid[i][j]==0){
               count++;
           } 
        }
       
    }
         if(count==n*m){
            return 0;
        }
       
        return 2;
       
    }
};