#include <vector>
#include <string>
using namespace std;

class disjointSet {
    vector<int> rank, parent;
public:
    disjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int findUParent(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }
    
    void unionByRank(int u, int v) {
        int ultpu = findUParent(u);
        int ultpv = findUParent(v);
        if (ultpu == ultpv) {
            return;
        }
        if (rank[ultpu] > rank[ultpv]) {
            parent[ultpv] = ultpu;
        } else if (rank[ultpu] < rank[ultpv]) {
            parent[ultpu] = ultpv;
        } else {
            parent[ultpv] = ultpu;
            rank[ultpu]++;
        }
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        disjointSet ds((n + 1) * (n + 1));
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0 || i == n || j == n) {
                    int node = (i * (n + 1) + j);
                
                    ds.unionByRank(0, node);    
                    
                    
                }
            }
        }
        
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                pair<int,int>p1={i,j+1};
                    pair<int,int>p2={i+1,j};
                    int node1=p1.first*(n+1)+p1.second;
                    int node2=p2.first*(n+1)+p2.second;
                    if(ds.findUParent(node1)==ds.findUParent(node2)){
                        ans++;
                    }
                   ds.unionByRank(node1,node2); 
                } else if (grid[i][j] == '\\') {
                    pair<int,int>p1={i,j};
                    pair<int,int>p2={i+1,j+1};
                   int node1=p1.first*(n+1)+p1.second;
                    int node2=p2.first*(n+1)+p2.second;
                    if(ds.findUParent(node1)==ds.findUParent(node2)){
                        ans++;
                    }
                   ds.unionByRank(node1,node2);  
                }
            }
        }
        
        return ans;
    }
};
