class Solution {
    bool dfs(int node,vector<int>&vis,vector<int>adj[],int parent){
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                if(dfs(it,vis,adj,node)){
                    return true;
                }
            }
            else if(it!=parent){
                return true;
            }
        }
        return false;
    }
public:
    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<int>adj[V];
        int e=edges.size();
        for(int i=0;i<e;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>vis(V,0);
        int parent=-1;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                vis[i]=1;
                 if(dfs(i,vis,adj,parent)){
                
                return true;
            }
            }
           
        }
        return false;
    }
};