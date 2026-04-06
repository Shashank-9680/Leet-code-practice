class Solution {
  public:
    vector<int> shortestPath(int V, int m, vector<vector<int>>& edges) {
        // Code here
         vector<pair<int,int>>adj[V+1];
          for(auto it:edges){
              adj[it[0]].push_back({it[1],it[2]});
              adj[it[1]].push_back({it[0],it[2]});
          }
          
          vector<int>parent(V+1);
          vector<int>dist(V+1,INT_MAX);
          
          for(int i=1;i<=V;i++){
              parent[i]=i;
          }
          
          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
          pq.push({0,1});
          dist[1]=0;
          
          while(!pq.empty()){
              int node=pq.top().second;
              int weight=pq.top().first;
              pq.pop();
              for(auto it:adj[node]){
                  if(weight+it.second<dist[it.first]){
                      dist[it.first]=it.second+weight;
                      pq.push({dist[it.first],it.first});
                      parent[it.first]=node;
                  }
              }
          }
          
       if(dist[V] == INT_MAX) return {-1};

     
        vector<int> path;
        int node = V;

        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);

        reverse(path.begin(), path.end());

    
        vector<int> ans;
        ans.push_back(dist[V]);

        for(auto x : path){
            ans.push_back(x);
        }

        return ans;
    }
};