class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,-1);
        queue<int>q;
     
       for (int i = 0; i < n; i++) {
            if (vis[i] == -1) { 
                queue<int> q;
                vis[i] = 0;
                q.push(i);

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int adjNode : graph[node]) {
                        if (vis[adjNode] != -1) {
                            if (vis[adjNode] == vis[node]) {
                                return false;
                            }
                        } else {
                            vis[adjNode] = !vis[node];  // Assign the opposite color
                            q.push(adjNode);
                        }
                    }
                }
            }
        }
        return true;
    }
};