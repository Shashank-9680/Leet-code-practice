class Solution {
    bool dfs(int node,vector<vector<int>>&edges,vector<int>&vis,vector<int>&pathVis,vector<int>&ans){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:edges[node]){
            if(!vis[it]){
                if(dfs(it,edges,vis,pathVis,ans)){
                    return true;
                }
            }
            else if(pathVis[it]){
                return true;
            }
            
        }
        
           ans.push_back(node);  

        pathVis[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& edges) {
        int V=edges.size();
        vector<int>vis(V,0);
        vector<int>pathVis(V,0);
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,edges,vis,pathVis,ans);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};