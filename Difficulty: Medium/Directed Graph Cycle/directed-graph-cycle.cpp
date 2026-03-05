class Solution {
    bool dfs(int node,vector<int>&vis,vector<int>&pathVis,vector<int>adj[]){
        
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                pathVis[it]=1;
                if(dfs(it,vis,pathVis,adj)){
                    return true;
                }
            }
            else if(pathVis[it]==vis[it]){
                return true;
            }
        }
        pathVis[node]=0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int>adj[V];
        int e=edges.size();
        for(int i=0;i<e;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<int>vis(V,0);
        vector<int>pathVis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                vis[i]=1;
                pathVis[i]=1;
                if(dfs(i,vis,pathVis,adj)){
               return true;
                }
            }
        }
        return false;
    }
};