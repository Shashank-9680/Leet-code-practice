class Solution {
public:
    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<int> adj[V];

        // build adjacency list
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V,0);

        for(int i=0;i<V;i++){

            if(!vis[i]){

                queue<pair<int,int>> q;
                q.push({i,-1});
                vis[i] = 1;

                while(!q.empty()){

                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();

                    for(auto it: adj[node]){

                        if(!vis[it]){
                            vis[it] = 1;
                            q.push({it,node});
                        }

                        else if(parent != it){
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }
};