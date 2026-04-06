// User function Template for C++
class Solution {
    void dfs(int node, vector<pair<int,int>>adj[], int V, stack<int>&st,
    vector<int>&vis){
        vis[node]=0;
        for(auto it:adj[node]){
            if(!vis[it.first]){
                dfs(it.first,adj,V,st,vis);
                vis[it.first]=1;
            }
        }
        st.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
          vector<pair<int,int>>adj[V];
          for(auto it:edges){
              adj[it[0]].push_back({it[1],it[2]});
          }
          vector<int>vis(V,0);
          
          stack<int>st;
          dfs(0,adj,V,st,vis);
          
          vector<int>dist(V,INT_MAX);
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
              if(dist[i]==INT_MAX) dist[i]=-1;
          }
          return dist;
        
    }
};
