class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        queue<pair<int,int>> q;
        q.push({0,0});

        dist[0][0] = 1;

        vector<pair<int,int>> neig = {
            {-1,0},{0,-1},{1,0},{0,1},
            {1,1},{-1,-1},{-1,1},{1,-1}
        };

        while(!q.empty()){

            auto it = q.front();
            int row = it.first;
            int col = it.second;
            q.pop();

            for(auto d : neig){

                int nrow = row + d.first;
                int ncol = col + d.second;

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0){

                    if(dist[row][col] + 1 < dist[nrow][ncol]){

                        dist[nrow][ncol] = dist[row][col] + 1;
                        q.push({nrow,ncol});

                    }
                }
            }
        }

        if(dist[n-1][m-1] == 1e9) return -1;

        return dist[n-1][m-1];
    }
};