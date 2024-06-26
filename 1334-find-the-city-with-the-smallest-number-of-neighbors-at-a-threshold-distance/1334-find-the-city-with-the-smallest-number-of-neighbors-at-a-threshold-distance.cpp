class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
      int m=edges[0].size();
       vector<vector<int>>v(n,vector<int>(n,INT_MAX));
        for(auto it:edges){
           v[it[0]][it[1]]=it[2];
            v[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++){
            v[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(v[i][k]!=INT_MAX&&v[j][k]!=INT_MAX&&v[i][j]>v[i][k]+v[k][j]){
                        v[i][j]=v[i][k]+v[k][j];
                    }
                }
            }
        }
        int max=n;
        int cityNo=-1;
        for(int city=0;city<n;city++){
            int count=0;
            for(int adjcity=0;adjcity<n;adjcity++){
                if(v[city][adjcity]<=distanceThreshold){
                    count++;
                }
                
            }
            if(count<=max){
                max=count;
                cityNo=city;
            }
        }
        return cityNo;
    }
};