class Solution {
public:
    void solve(vector<vector<char>>& board) {
       int n=board.size();
       int m=board[0].size();
       queue<pair<int,int>>q;
     vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

       vector<vector<int>>vis(n,vector<int>(m,0));
       for(int i=0;i<m;i++){
         if(board[0][i]=='O'){
            q.push({0,i});
            vis[0][i]=1;
         }
       }
       for(int j=1;j<n;j++){
        if(board[j][0]=='O'){
            q.push({j,0});
            vis[j][0]=1;
        }
       }
       for(int i=1;i<m;i++){
        if(board[n-1][i]=='O'){
            q.push({n-1,i});
            vis[n-1][i]=1;
        }
       }
       for(int j=1;j<n-1;j++){
        if(board[j][m-1]=='O'){
            q.push({j,m-1});
            vis[j][m-1]=1;
        }
       }
       while(!q.empty()){
        int row=q.front().first;
        int col =q.front().second;
        q.pop();
        for(auto it:dir){
            int nrow=it.first+row;
            int ncol=it.second+col;
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]){
                if(board[nrow][ncol]=='O'){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
       }
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='O'&&vis[i][j]==0){
                board[i][j]='X';
            }
        }
       }
    }
};