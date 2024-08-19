class Solution {
  
public:
    int minSteps(int n) {
     vector<int>v(n+1);
        if(n==1){
            return 0;
        }
        if(n==2){
            return 2;
        }
        v[1]=0;
        v[2]=2;
        for(int i=3;i<=n;i++){
            int j=i/2;
            v[i]=i;
            while(j>=1){
              if(i%j==0){
                 v[i]=min(v[i],v[j]+i/j); 
              }  
                j--;
            }
        }
        return v[n];
    }
};