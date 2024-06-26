class Solution {
    class DisjointSet {
    vector<int> rank, parent, size;
public:
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
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
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
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet st(n);
        int countxedges=0;
        for(auto it:connections){
            int i=it[0];
            int j=it[1];
            if(st.findUPar(i)==st.findUPar(j)){
                countxedges++;
            }
            else{
                st.unionBySize(i,j);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(st.findUPar(i)==i){
                count++;
            }
        }
        int ans=count-1;
        if(ans<=countxedges){
            return ans;
        }
        else{
            return -1;
        }
    }
};