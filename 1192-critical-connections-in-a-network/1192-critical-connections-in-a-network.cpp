class Solution {
    int timer=1;
    void dfs(int node,int parent,vector<int>adj[],int tin[],int low[],vector<vector<int>>&bridges,vector<int>&vis){
        vis[node]=1;
        tin[node]=timer;
        low[node]=timer;
        timer++;
        
        for(auto it:adj[node]){
              if(it==parent) continue;
            if(vis[it]==0){
              dfs(it,node,adj,tin,low,bridges,vis);  
             
                low[node]=min(low[it],low[node]);
                if(low[it]>tin[node]){
                    bridges.push_back({it,node});
                }
            }
             else{
                 low[node]=min(low[it],low[node]);   
            }
            
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>vis(n,0);
        int tin[n];
        int low[n];
        vector<int>adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
            
        }
        vector<vector<int>>bridges;
        dfs(0,-1,adj,tin,low,bridges,vis);
        return bridges;
    }
};