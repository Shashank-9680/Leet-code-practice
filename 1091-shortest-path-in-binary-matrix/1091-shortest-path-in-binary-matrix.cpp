class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>v(n,vector<int>(m,INT_MAX));
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});
        v[0][0]=0;
            if (grid[0][0] != 0 || grid[n-1][m-1] != 0) return -1;
        while(!q.empty()){
            int weight=q.front().first;
            int node1=q.front().second.first;
            int node2=q.front().second.second;
            q.pop();
            
       for(int nr=-1;nr<=1;nr++){
           for(int nc=-1;nc<=1;nc++){
               int nrow=node1+nr;
               int ncol=node2+nc;
               if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&grid[nrow][ncol]==0){
                   if(1+weight<v[nrow][ncol]){
                       v[nrow][ncol]=1+weight;
                       q.push({v[nrow][ncol],{nrow,ncol}});
                   }
               }
           }
       
       }     
        }
         return (v[n-1][m-1] == INT_MAX) ? -1 : v[n-1][m-1]+1;
       
    }
};