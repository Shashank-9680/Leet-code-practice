#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> dis1(n + 1, INT_MAX);
        vector<int> dis2(n + 1, INT_MAX);
        
        queue<pair<int, int>> q;
        dis1[1] = 0;
        q.push({0, 1});
        
        while (!q.empty()) {
            int dist = q.front().first;
            int node = q.front().second;
            q.pop();
            
            int waitTime = 0;
            if ((dist / change) % 2 == 1) { // Red light
                waitTime = change - (dist % change);
            }
            dist += waitTime + time;
            
            for (int neighbor : adj[node]) {
                if (dist < dis1[neighbor]) {
                    dis2[neighbor] = dis1[neighbor];
                    dis1[neighbor] = dist;
                    q.push({dis1[neighbor], neighbor});
                } else if (dist > dis1[neighbor] && dist < dis2[neighbor]) {
                    dis2[neighbor] = dist;
                    q.push({dis2[neighbor], neighbor});
                }
            }
        }
        
        return dis2[n] == INT_MAX ? 0 : dis2[n];
    }
};
