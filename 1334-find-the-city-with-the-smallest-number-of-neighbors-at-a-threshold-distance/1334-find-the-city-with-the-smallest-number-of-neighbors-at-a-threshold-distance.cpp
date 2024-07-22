class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>>vis(n,vector<int>(n,1e9));
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            vis[u][v]=w;
            vis[v][u]=w;
        }
        for(int i=0;i<n;i++){
            vis[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(vis[i][k]!=1e9||vis[k][j]!=1e9){
                        vis[i][j]=min(vis[i][k]+vis[k][j],vis[i][j]);
                    }
                }
            }
        }
        
       
        int maxcity=n;
        int city=-1;
        for(int i=0;i<n;i++){
             int count=0;
            for(int j=0;j<n;j++){
                if(vis[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=maxcity){
                maxcity=count;
                city=i;
            }
        }
        return city;
    }
};