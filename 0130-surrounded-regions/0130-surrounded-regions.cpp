class Solution {
    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>&vis){
        vis[row][col]=1;
          int n=board.size();
        int m=board[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
         for (auto dir : directions) {
                    int nrow = row + dir.first;
                    int ncol = col + dir.second;

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&vis[nrow][ncol]!=1&&board[nrow][ncol] == 'O'){
                     dfs(nrow,ncol,board,vis);
                      
                    }
                    }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
       vector<vector<int>>vis(n,vector<int>(m,0)); 
        for(int j=0;j<m;j++){
            if(!vis[0][j]&&board[0][j]=='O'){
                dfs(0,j,board,vis);
            }
            if(!vis[n-1][j]&&board[n-1][j]=='O'){
                dfs(n-1,j,board,vis);
            }
        }
        for(int i=1;i<n-1;i++){
            if(!vis[i][0]&&board[i][0]=='O'){
                dfs(i,0,board,vis);
            }
            if(!vis[i][m-1]&&board[i][m-1]=='O'){
                dfs(i,m-1,board,vis);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};