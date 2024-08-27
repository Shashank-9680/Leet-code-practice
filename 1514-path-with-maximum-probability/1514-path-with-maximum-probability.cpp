class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int, double>> adj[n];
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

       
        vector<double> dist(n, 0.0);
        dist[start_node] = 1.0; 

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        while (!pq.empty()) {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop(); 
            if (node == end_node) return prob;
            for (auto& it : adj[node]) {
                int adjNode = it.first;
                double edgeProb = it.second;
                if (prob * edgeProb > dist[adjNode]) {
                    dist[adjNode] = prob * edgeProb;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return 0.0;
        
    }
};