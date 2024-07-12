class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>>ans(n);
        ans[0]={1};
        if(n==1){
            return ans;
        }
        
        else{
            for(int i=1;i<n;i++){
                int size=ans[i-1].size();
                
             
                ans[i].push_back(1);
               for(int j=0;j<size-1;j++){
                  int sum=ans[i-1][j]+ans[i-1][j+1];
                    ans[i].push_back(sum);
                }
                ans[i].push_back(1);
            }
        }
        return ans;
    }
};