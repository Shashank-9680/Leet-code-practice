class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<
        int,int>>>pq;
        dist[k]=0;
        pq.push({0,k});
        unordered_set<int>s;
        int count=0;
        int time=0;
        while(!pq.empty()){
           bool val=false;
           int dis=pq.top().first;
           int node=pq.top().second;
           pq.pop();
           if(dist[node]!=1e9){
               s.insert(node);
            }
            int count=s.size();
           if(count==n){
              return dis;
           }
           for(auto it:adj[node]){
              if(dis+it.second<dist[it.first]){
                dist[it.first]=dis+it.second;
                pq.push({dist[it.first],it.first});
                val=true;
              }
           }

        }
    return -1;
    }
};