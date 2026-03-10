// User function Template for C++
class Solution {
    void dfs(int node,vector<pair<int,int>>adj[],stack<int>&st,vector<int>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it.first]){
                dfs(it.first,adj,st,vis);
            }
        }
        st.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>>adj[V];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        stack<int>st;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,st,vis);
            }
        }
        
        vector<int>dist(V,1e9);
        dist[0]=0;
        
        while(!st.empty()){
           int node=st.top();
           st.pop();
           for(auto it:adj[node]){
               if(dist[node]+it.second<dist[it.first]){
                   dist[it.first]=dist[node]+it.second;
               }
           }
        }
        for(int i=0;i<V;i++){
            if(dist[i]==1e9) dist[i]=-1;
        }
        return dist;
    }
};
