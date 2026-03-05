class Solution {
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis,
             vector<int> adj[], vector<int>& ans) {

        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : adj[node]) {

            if(!vis[it]) {
                if(dfs(it, vis, pathVis, adj, ans)) {
                    return true;
                }
            }
            else if(pathVis[it]) {
                return true;
            }
        }

        ans.push_back(node);
        pathVis[node] = 0;

        return false;
    }

public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {

        vector<int> adj[V];

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
        }

        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        vector<int> ans;

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, vis, pathVis, adj, ans);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};