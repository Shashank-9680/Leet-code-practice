class Solution {
  public:
  void dfs(int node,vector<int>adj[],stack<int>&st,vector<int>&vis){
      vis[node]=1;
      for(auto it:adj[node]){
          if(!vis[it]){
              dfs(it,adj,st,vis);
          }
      }
      st.push(node);
  }
  void dfs1(int node,vector<int>adjT[],vector<int>&vis){
      vis[node]=1;
      for(auto it:adjT[node]){
          if(!vis[it]){
              dfs1(it,adjT,vis);
          }
      }
  }
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        vector<int>adj[V];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int>vis(V,0);
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,st,vis);
            }
        }
        
        vector<int>adjT[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
        }
         for(auto it:edges){
            adjT[it[1]].push_back(it[0]);
        }
        int count=0;
        while(!st.empty()){
             int val=st.top();
             st.pop();
            if(!vis[val]){
                count++;

                dfs1(val,adjT,vis);
            }
        }
        return count;
        
    }
};