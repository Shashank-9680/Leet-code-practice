class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans=mat;
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
         vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},1});
                    vis[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int row=q.front().first.first;
                int col=q.front().first.second;
                int count =q.front().second;
                q.pop();
                for(auto it:dir){
                    int nrow= row+it.first;
                    int ncol =col+it.second;
                    if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m){
                        if(mat[nrow][ncol]==1&&!vis[nrow][ncol]){
                            q.push({{nrow,ncol},count+1});
                            ans[nrow][ncol]=count;
                            vis[nrow][ncol]=1;
                        }
                    }
                }
            }
        }
    return ans;
    }
};