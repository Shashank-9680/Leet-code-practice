class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        vector<pair<int,int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
        int fresh=0;
        int time=0;
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({i,j});
                vis[i][j]=1;
            }
            else if(grid[i][j]==1){
                fresh++;
            }
          }
        }
        while(!q.empty()){
            int size=q.size();
            bool isRotten=false;
            for(int i=0;i<size;i++){
                int row=q.front().first;
                int col=q.front().second;
                 q.pop();
                 for(auto it:dir){
                    int nrow=row+it.first;
                    int ncol=col+it.second;
                    if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]){
                        if(grid[nrow][ncol]==1){
                            q.push({nrow,ncol});
                            grid[nrow][ncol]=2;
                            vis[nrow][ncol]=1;
                            isRotten=true;
                            fresh--;
                        }
                    }
                 }
            }
            if(isRotten) time++;
            

        }
        if(fresh==0) return time;
        return -1;
    }
};