class Solution {
   
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
      vector<vector<int>>ans(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
      
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},1});
                    vis[i][j]=1;
                }
            }
        }
        vector<pair<int,int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
        while(!q.empty()){
            auto it=q.front();
            int row=it.first.first;
            int col=it.first.second;
            int dis=it.second;
            q.pop();
            for(auto it:dir){
                int nrow=row+it.first;
                int ncol=col+it.second;
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]){
                    if(mat[nrow][ncol]==1){
                        ans[nrow][ncol]=dis;
                        q.push({{nrow,ncol},dis+1});
                        vis[nrow][ncol]=1;
                    }
                }
            }
            
        }
        return ans;
    }
};