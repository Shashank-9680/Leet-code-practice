class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

        int count = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]=='1' && !vis[i][j]){

                    count++;

                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j]=1;

                    while(!q.empty()){
                        int row=q.front().first;
                        int col=q.front().second;
                        q.pop();

                        for(auto it:dir){
                            int nrow=row+it.first;
                            int ncol=col+it.second;

                            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                                if(grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                                    q.push({nrow,ncol});
                                    vis[nrow][ncol]=1;
                                }
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};