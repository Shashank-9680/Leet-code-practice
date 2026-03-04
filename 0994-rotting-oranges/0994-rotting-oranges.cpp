class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int time=0;
        while(!q.empty()){
            int size=q.size();
            bool ifPresent=false;
            for(int it=0;it<size;it++){
               int row=q.front().first;
               int col=q.front().second;
               q.pop();
               for(auto iter:dir){
                int nrow=row+iter.first;
                int ncol =col+iter.second;
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]){
                    if(grid[nrow][ncol]==1){
                        grid[nrow][ncol]=2;
                        fresh--;
                        ifPresent=true;
                        q.push({nrow,ncol});
                    }
                }
                
               }
            }
            if(ifPresent) time++;
        } 
        if(fresh==0) return time;
        return -1;
    }   
};