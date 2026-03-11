class DisjointSet{
    public:
    vector<int>rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    
    int findParent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }
    
    void UnionByRank(int u,int v){
        int ultp_u= findParent(u);
        int ultp_v= findParent(v);
        if(ultp_u==ultp_v) return;
        if(rank[ultp_u]<rank[ultp_v]){
            parent[ultp_u]=ultp_v;
        }
        else if(rank[ultp_u]>rank[ultp_v]){
            parent[ultp_v]=ultp_u;
        }
        else{
            rank[ultp_u]++;
            parent[ultp_v]=ultp_u;
        }
    }
    
    void UnionBySize(int u,int v){
        int ultp_u= findParent(u);
        int ultp_v= findParent(v);
        if(ultp_u==ultp_v) return;
        if(size[ultp_u]<size[ultp_v]){
            parent[ultp_u]=ultp_v;
            size[ultp_v]+=size[ultp_u];
        }
        else{
            parent[ultp_v]=ultp_u;
            size[ultp_u]+=size[ultp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int V, vector<vector<int>>& connections) {
        DisjointSet ds(V);
        int count=0;
        int extraEdges=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findParent(u)!=ds.findParent(v)){
                ds.UnionBySize(u,v);
            }
            else{
                extraEdges++;
            }
        }
        for(int i=0;i<V;i++){
            if(ds.parent[i]==i){
               count++;
            }
        }
       int ans=count-1;
        if(extraEdges>=ans) return ans;
        return -1;
    }
};