class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
      vector<int>prefixXor(arr.size());
     int xorrr=0;
        for(int i=0;i<arr.size();i++){
            xorrr=arr[i]^xorrr;
            prefixXor[i]=xorrr;
           
        }
        for(auto it:queries){
          if(it[0]==it[1]){
              ans.push_back(arr[it[0]]);
          }
           else{
               if(it[0]!=0){
                   int xorr=0;
                   for(int i=0;i<it[0];i++){
                       xorr=xorr^arr[i];
                   }
                   ans.push_back(xorr^prefixXor[it[1]]);
               }
               else{
                   ans.push_back(prefixXor[it[1]]);
               }
           } 
        }
        return ans;
    }
};