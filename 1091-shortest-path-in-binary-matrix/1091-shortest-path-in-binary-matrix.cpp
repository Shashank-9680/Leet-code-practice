class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
       if(n==1&&grid[0][0]==0){
           return 1;
       }
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});
        if(grid[0][0]!=0||grid[n-1][n-1]!=0) return -1;
        dist[0][0]=1;
        while(!q.empty()){
            int dis=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int rc=-1;rc<=1;rc++){
                for(int cc=-1;cc<=1;cc++){
                    int nrow=row+rc;
                    int ncol=col+cc;  
                    if(nrow>=0&&nrow<n&&ncol>=0&&ncol<n){
                       if(grid[nrow][ncol]==0){
                           if(dis+1<dist[nrow][ncol]){
                               dist[nrow][ncol]=dis+1;
                               q.push({dist[nrow][ncol],{nrow,ncol}});
                           }
                       } 
                    }
                }     
            }
        }
       if(dist[n-1][n-1]==INT_MAX){
           return -1;
       }
        return dist[n-1][n-1]+1;
    }
};