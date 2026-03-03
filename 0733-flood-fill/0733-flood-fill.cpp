class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m = image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans=image;
        queue<pair<int,int>>q;
        ans[sr][sc]=color;
        vis[sr][sc]=1;
        q.push({sr,sc});
        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty()){
          int row=q.front().first;
          int col =q.front().second;
          q.pop();
          for(auto it:dir){
            int nrow= row+it.first;
            int ncol =col+it.second;
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&& !vis[nrow][ncol]){
                if(image[nrow][ncol]==image[sr][sc]){
                    q.push({nrow,ncol});
                    ans[nrow][ncol]=color;
                    vis[nrow][ncol]=1;
                }
            }
          }
        }
        return ans;
    }
};