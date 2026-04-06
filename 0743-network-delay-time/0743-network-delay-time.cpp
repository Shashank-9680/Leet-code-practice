class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int,int>> adj[n+1];

        for(auto it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n+1, 1e9);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            auto [dis, node] = pq.top();
            pq.pop();

            // // 🔥 Skip outdated entries
            // if(dis > dist[node]) continue;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;

                if(dis + wt < dist[adjNode]){
                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }


        int maxi = 0;

        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e9) return -1; // unreachable
            maxi = max(maxi, dist[i]);
        }

        return maxi;
    }
};