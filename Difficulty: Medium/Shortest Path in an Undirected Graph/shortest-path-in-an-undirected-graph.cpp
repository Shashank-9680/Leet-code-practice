class Solution {
  public:
    vector<int> shortestPath(int N, int m, vector<vector<int>>& edges) {
         vector<pair<int,int>>adj[N+1];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
      vector<int>parent(N+1);
      for(int i=1;i<=N;i++){
          parent[i]=i;
      }
      vector<int>dist(N+1,1e9);
      dist[1]=0;
      
      
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
      pq.push({0,1});
      while(!pq.empty()){
          int dis=pq.top().first;
          int node=pq.top().second;
          pq.pop();
          for(auto it:adj[node]){
              if(dist[node]+it.second<dist[it.first]){
                  dist[it.first]=dist[node]+it.second;
                  parent[it.first]=node;
                  pq.push({dist[it.first],it.first});
              }
          }
      }
     
      if(dist[N]==1e9) return {-1};

        vector<int> ans;
        int node=N;

        while(parent[node]!=node){
            ans.push_back(node);
            node=parent[node];
        }

        ans.push_back(1);

        reverse(ans.begin(),ans.end());
         ans.insert(ans.begin(), dist[N]);
      return ans;
    }
};