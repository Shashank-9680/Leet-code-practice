class Solution {
    void dfs(int row,int col,vector<vector<int>>& board,vector<vector<int>>&vis){
        vis[row][col]=1;
          int n=board.size();
        int m=board[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
         for (auto dir : directions) {
                    int nrow = row + dir.first;
                    int ncol = col + dir.second;

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&vis[nrow][ncol]!=1&&board[nrow][ncol] == 1){
                     dfs(nrow,ncol,board,vis);
                      
                    }
                    }
    }
public:
    int numEnclaves(vector<vector<int>>& board) {
         int n=board.size();
        int m=board[0].size();
       vector<vector<int>>vis(n,vector<int>(m,0)); 
        for(int j=0;j<m;j++){
            if(!vis[0][j]&&board[0][j]==1){
                dfs(0,j,board,vis);
            }
            if(!vis[n-1][j]&&board[n-1][j]==1){
                dfs(n-1,j,board,vis);
            }
        }
        for(int i=1;i<n-1;i++){
            if(!vis[i][0]&&board[i][0]==1){
                dfs(i,0,board,vis);
            }
            if(!vis[i][m-1]&&board[i][m-1]==1){
                dfs(i,m-1,board,vis);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (board[i][j] == 1 && vis[i][j] == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};