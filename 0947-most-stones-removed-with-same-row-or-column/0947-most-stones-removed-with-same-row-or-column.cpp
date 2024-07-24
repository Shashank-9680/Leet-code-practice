class disjointSet{
   
    public:
     vector<int>rank,parent,size;
    disjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }
    void unionByRank(int u,int v){
        int ultp_u=findParent(u);
        int ultp_v=findParent(v);
        if(ultp_u==ultp_v) return;
        if(rank[ultp_u]==rank[ultp_v]){
            parent[ultp_v]=ultp_u;
            rank[ultp_u]++;
        }
        else if(rank[ultp_u]>rank[ultp_v]){
            parent[ultp_v]=ultp_u;
        }
        else{
             parent[ultp_u]=ultp_v;
        }
    }
     void unionBySize(int u,int v){
        int ultp_u=findParent(u);
        int ultp_v=findParent(v);
        if(ultp_u==ultp_v) return;
        if(size[ultp_u]==size[ultp_v]){
            parent[ultp_v]=ultp_u;
            size[ultp_u]=size[ultp_u]+size[ultp_v];
        }
        else if(size[ultp_u]>size[ultp_v]){
            parent[ultp_v]=ultp_u;
            size[ultp_u]=size[ultp_u]+size[ultp_v];
        }
        else{
             parent[ultp_u]=ultp_v;
              size[ultp_v]=size[ultp_v]+size[ultp_u];
        }
    }
    
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
       int maxRow=0;
        int maxCol=0;
        for(auto it:stones){
            maxRow=max(it[0],maxRow);
            maxCol=max(it[1],maxCol);
        }
        disjointSet ds(maxRow+maxCol+1);
        // unordered_map<int,int>m;
        unordered_set<int>s;
        for(auto it:stones){
            int row=it[0];
            int col=it[1]+maxRow+1;
            ds.unionBySize(row,col);            
        }
        
        // vector<int>arr=ds.parent;
        for (auto it : stones) {
            int row = it[0];
            int col=it[1]+maxRow+1;
            s.insert(ds.findParent(row));
            s.insert(ds.findParent(col));
        }
        return n-s.size();
    }
};