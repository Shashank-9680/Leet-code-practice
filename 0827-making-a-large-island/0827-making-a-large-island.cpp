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
        int n=grid.size();
        int m=grid[0].size();
      DisjointSet ds(n*m);
        vector<pair<int,int>>directions={{-1,0},{0,-1},{1,0},{0,1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;
                
              for(auto it:directions){
                  int nrow=i+it.first;
                  int ncol=j+it.second;
                  if(isValid(nrow,ncol,n,m)&&grid[nrow][ncol]==1){
                      int node1=i*m+j;
                      int node2=nrow*m+ncol;
                      ds.unionBySize(node1,node2);
                  }
              }
            }
        }
        int mx=0;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
               if(grid[i][j]==1) continue;
                set<int>components;
              for(auto it:directions){
                  int nrow=i+it.first;
                  int ncol=j+it.second;
                  if(isValid(nrow,ncol,n,m)&&grid[nrow][ncol]==1){
                     components.insert({ds.findUPar(nrow*m+ncol)});
                  }
              } 
              int sizeTotal=0;
                for(auto it:components){
                    sizeTotal+=ds.size[it];
                    mx=max(mx,sizeTotal+1);
                }
            }
        
        }
        for(int i=0;i<n*n;i++){
            mx=max(mx,ds.size[ds.findUPar(i)]);
        }
        return mx;
    }
};