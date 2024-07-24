class disjointSet{   
    public:
     vector<int>rank,parent,size;
    disjointSet(int n){
        rank.resize(n+1,0);
         parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(parent[node]==node){
            return node;
        }
        return node=findParent(parent[node]);
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjointSet ds(n);
        int count=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findParent(u)!=ds.findParent(v)){
               ds.unionBySize(u,v);
            }
            else{
                count++;
            }
        }
        int count1=0;
        vector<int>arr=ds.parent;
        for(int i=0;i<n;i++){
            if(arr[i]==i){
                count1++;
            }
        }
        int count2=count1-1;
        if(count>=count2){
            return count2;
        }
        return -1;
    }
};