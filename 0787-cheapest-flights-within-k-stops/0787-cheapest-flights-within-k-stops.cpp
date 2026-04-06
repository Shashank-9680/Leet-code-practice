class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;
        int count=0;
        pq.push({count,{0,src}});
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        while(!pq.empty()){
            int remCount=pq.top().first;
            int cost=pq.top().second.first;
            int node=pq.top().second.second;
             
            pq.pop();

            if(remCount>k){
                if(node==dst) return dist[dst];
                else{
                    continue;
                }
            }

            for(auto it:adj[node]){
               if(it.second+cost<dist[it.first]){
                dist[it.first]=it.second+cost;
                pq.push({remCount+1,{dist[it.first],it.first}});
               }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};