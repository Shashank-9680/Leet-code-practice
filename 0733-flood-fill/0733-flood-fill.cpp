class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int initial=image[sr][sc];
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 vis[i][j]=image[i][j];
             }
         }
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=color;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for (auto dir : directions) {
                    int nrow = row + dir.first;
                    int ncol = col + dir.second;

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initial&&vis[nrow][ncol]!=color){
                      vis[nrow][ncol]=color;
                       q.push({nrow, ncol});
                    }
                    }
                }
          return vis;  
       }
    
    
    
};