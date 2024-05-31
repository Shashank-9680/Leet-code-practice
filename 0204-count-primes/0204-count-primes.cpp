class Solution {
public:
    int countPrimes(int n) {
     vector<int>v(n,1);
         if (n <= 2) return 0;
          // v[0]=v[1] = 0;
        int count=0;
       
        for(int i=2;i*i<n;i++){
            if(v[i]==1){
                for(int j=i*i;j<n;j+=i){
                    v[j]=0;
                }
            }
        }
        for(int i=2;i<n;i++){
            if(v[i]==1){
                count++;
            }
        }
      return count;
    }
};