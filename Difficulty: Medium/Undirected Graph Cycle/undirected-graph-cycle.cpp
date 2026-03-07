class Solution {
    
    bool bfs(int node,vector<int>adj[],vector<int>&vis,queue<pair<int,int>>&q){
        vis[node]=1;
        q.push({node,-1});
        while(!q.empty()){
            int val=q.front().first;
            int par=q.front().second;
            q.pop();
            for(auto it:adj[val]){
                if(!vis[it]){
                    q.push({it,val});
                    vis[it]=1;
                }
                else if(par!=it){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        vector<int>adj[V];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(V,0);
        queue<pair<int,int>>q;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(bfs(i,adj,vis,q)){
                    return true;
                }
            }
        }
        return false;
    }
};