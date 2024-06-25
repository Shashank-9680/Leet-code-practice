class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
       vector<pair<int, int>> adj[n];
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Priority queue to store (distance, node)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        q.push({0, 0});

        vector<long long> dist(n, LLONG_MAX); // Use long long to avoid overflow
        vector<int> way(n, 0);
        dist[0] = 0;
        way[0] = 1;

        int mod = 1e9 + 7;

        while (!q.empty()) {
            long long dis = q.top().first;
            int node = q.top().second;
            q.pop();

            for (auto it : adj[node]) {
                int adjnode = it.first;
                int cost = it.second;

                if (dis + cost < dist[adjnode]) {
                    dist[adjnode] = dis + cost;
                    way[adjnode] = way[node];
                    q.push({dist[adjnode], adjnode});
                } else if (dis + cost == dist[adjnode]) {
                    way[adjnode] = (way[adjnode] + way[node]) % mod;
                }
            }
        }

        return way[n - 1];
        
    }
};