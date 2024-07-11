class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
          vector<vector<int>>result=image;
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int initialColor = result[sr][sc];
        result[sr][sc]=color;
        vis[sr][sc]=1;
        vector<pair<int,int>>d={{-1,0},{0,-1},{0,1},{1,0}};
        
        while(!q.empty()){
            auto it=q.front();
            int row=it.first;
            int col=it.second;
             q.pop();
            // result[row][col]=color;
            for(auto it:d){
                int nrow=row+it.first;
                int ncol=col+it.second;
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]){
                    if(result[nrow][ncol]==initialColor){
                   
                        result[nrow][ncol]=color;
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
                
            }
           
        }
        return result;
       }
    
    
    
};