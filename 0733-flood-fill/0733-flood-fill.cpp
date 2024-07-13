class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int n=grid.size();
        int m=grid[0].size();
        int intial=grid[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[sr][sc]=1;
        grid[sr][sc]=color;
        vector<pair<int,int>>dir={{-1,0},{0,-1},{0,1},{1,0}};
        while(!q.empty()){
            auto it=q.front();
            int row=it.first;
            int col=it.second;
            q.pop();
            for(auto it:dir){
                int nrow=row+it.first;
                int ncol=col+it.second;
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]){
                    if(grid[nrow][ncol]==intial){
                        q.push({nrow,ncol});
                        grid[nrow][ncol]=color;
                        vis[nrow][ncol]=1;
                    }
                }
            }
            
        }
        return grid;
       }
    
    
    
};