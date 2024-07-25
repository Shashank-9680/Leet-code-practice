class DisjointSet {
public:
    vector<int> rank, parent, size;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
private:
    bool isValid(int newr, int newc, int n, int m) {
        return newr >= 0 && newr < n && newc >= 0 && newc < m;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n * m);

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        // Step 1: Create disjoint sets for initial 1s
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 0) continue;
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n, m) && grid[newr][newc] == 1) {
                        int nodeNo = row * m + col;
                        int adjNodeNo = newr * m + newc;
                        if(ds.findUPar(nodeNo)!=ds.findUPar(adjNodeNo)){
                        ds.unionBySize(nodeNo, adjNodeNo);     
                        }
                       
                    }
                }
            }
        }

        // Step 2: Calculate max possible connection by flipping each 0 to 1
        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 1) continue;
                set<int> components;
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n, m) && grid[newr][newc] == 1) {
                        components.insert(ds.findUPar(newr * m + newc));
                    }
                }
                int sizeTotal = 0;
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal + 1);
            }
        }

        // Step 3: Check max size of any existing component
        for (int cellNo = 0; cellNo < n * m; cellNo++) {
            mx = max(mx, ds.size[ds.findUPar(cellNo)]);
        }

        return mx;
    }
};