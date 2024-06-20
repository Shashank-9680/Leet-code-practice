class Solution {
    void dfs(vector<vector<int>>&vis,vector<vector<char>>& grid,int row,int col){
          int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
    // queue<pair<int,int>>q;
    //     q.push({row,col});
        // while(!q.empty()){
        //     int currrow=q.front().first;
        //     int currcol=q.front().second;
        //     q.pop();
             vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
          for (auto dir : directions) {
                   int nrow=row+dir.first;
                    int ncol=col+dir.second;
                  if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                    !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                    // vis[nrow][ncol] = 1;
                    // q.push({nrow, ncol});
                       dfs(vis,grid,nrow,ncol);   
               }
           } 
        // }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]=='1'){
                    count++;
                    dfs(vis,grid,i,j);
                }
            }
        }
        return count;
    }
};