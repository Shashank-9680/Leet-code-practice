class Solution {
   
public:
    int orangesRotting(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
        
//         queue<pair<int, int>> q;
//         int freshOranges = 0;

//         // Step 1: Initialize the queue with all initially rotten oranges
//         for (int row = 0; row < n; ++row) {
//             for (int col = 0; col < m; ++col) {
//                 if (grid[row][col] == 2) {
//                     q.push({row, col});
//                 } else if (grid[row][col] == 1) {
//                     ++freshOranges;
//                 }
//             }
//         }

//         // If there are no fresh oranges, return 0
//         if (freshOranges == 0) return 0;

//         // Step 2: Perform BFS to rot adjacent fresh oranges
//         int minutes = 0;
//         vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

//         while (!q.empty()) {
//             int size = q.size();
//             bool rotted = false;
            
//             for (int i = 0; i < size; ++i) {
//                 int row = q.front().first;
//                 int col = q.front().second;
//                 q.pop();

//                 for (auto dir : directions) {
//                     int nrow = row + dir.first;
//                     int ncol = col + dir.second;

//                     if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
//                         grid[nrow][ncol] = 2;
//                         q.push({nrow, ncol});
//                         --freshOranges;
//                         rotted = true;
//                     }
//                 }
//             }

//             if (rotted) {
//                 ++minutes;
//             }
//         }

//         // If there are still fresh oranges left, return -1
//         return freshOranges == 0 ? minutes : -1;
         int n = grid.size();
         int m = grid[0].size();
          queue<pair<pair<int, int>, int>> q;
     vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                if(grid[i][j]==0){
                    vis[i][j]=0;
                } 
            }
        }
        int time=0;
         vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            
           
             
               
                q.pop();
             time=max(time,t);

                for (auto dir : directions) {
                    int nrow = row + dir.first;
                    int ncol = col + dir.second;

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                        grid[nrow][ncol] = 2;
                       q.push({{nrow, ncol}, t + 1});
                         vis[nrow][ncol]=2;
                    }
                }
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};