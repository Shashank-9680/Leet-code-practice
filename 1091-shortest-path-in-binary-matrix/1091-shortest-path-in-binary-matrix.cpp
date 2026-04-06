class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
         if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;
        q.push({0,0});
        dist[0][0]=1;
        vector<pair<int,int>>dir={{-1,0},{0,-1},{1,0},{0,1},{1,-1},{-1,1},{1,1},{-1,-1}};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(auto it:dir){
                int nrow=it.first+row;
                int ncol=it.second+col;
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<n&&grid[nrow][ncol]==0){
                    if(dist[row][col]+1<dist[nrow][ncol]){
                        dist[nrow][ncol]=dist[row][col]+1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        if(dist[n-1][n-1]==INT_MAX) return -1;
        return dist[n-1][n-1];
    }
};