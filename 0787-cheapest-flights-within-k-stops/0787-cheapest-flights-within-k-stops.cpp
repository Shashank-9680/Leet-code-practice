class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n,1e9);
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        pq.push({0,{src,0}});
        dist[src]=0;
        int ans=INT_MAX;
        while(!pq.empty()){
            int stops=pq.top().first;
            int node=pq.top().second.first;
            int dis=pq.top().second.second;
            pq.pop();
            if(stops>k){
                continue;
            }
            for(auto it:adj[node]){
                int adjNode=it.first;
                if(dis+it.second<dist[adjNode]&&stops<=k){
                    dist[adjNode]=dis+it.second;
                    pq.push({stops+1,{adjNode, dis+it.second}});
                } 
            }
        }
     if(dist[dst]==1e9) return -1;
     return dist[dst];
    }
};