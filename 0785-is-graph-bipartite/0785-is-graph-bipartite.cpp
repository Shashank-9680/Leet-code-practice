class Solution {
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis) {

    
    for(auto it:graph[node]){
        if(vis[it]==-1){
            vis[it]=!vis[node];
            if(!dfs(it,graph,vis)){
                return false;
            }
        }
        else if(vis[it]==vis[node]){
            return false;
        }

    }
            
      return true;          
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);

        for(int i = 0; i < n; i++){
            if(vis[i] == -1){
                vis[i] = 0;
                if(!dfs(i, graph, vis)){
                    return false;
                }
            }
        }

        return true;
    }
};