class Solution {
    
  public:
  int timer=1;
  bool ans=false;
    void dfs(int node,int parent,vector<int>adj[],int tim[], int low[],
    vector<int>&vis,int c,int d){
        vis[node]=1;
        tim[node]=low[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it,node,adj,tim,low,vis,c,d);
                low[node]=min(low[node],low[it]);
                if(low[it]>tim[node]){
                    if(((it==c)&&(node==d))||((it==d)&&(node==c))){
                        ans=true;
                    }
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
         
         vector<int>adj[V];
         for(auto it:edges){
             adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
         }
         vector<int>vis(V,0);
        int tim[V];
        int low[V];
        for(int i=0;i<V;i++){
             dfs(i,-1,adj,tim,low,vis,c,d);
        }
         if(ans){
             return true;
         }
         return false;
        
    }
};