class Solution {
    const int MODULO = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long int sum=0;
        int n=arr.size();
    stack<int>s1,s2;
        vector<int>v1(n),v2(n);
        for(int i=n-1;i>=0;i--){
            while(!s1.empty()&&arr[s1.top()]>=arr[i]){
                s1.pop();
            }
            if(!s1.empty()){
                  v1[i] = s1.top() - i - 1;
            }
            else{
                v1[i] = n - i - 1;
            }
            s1.push(i);
        }
         for(int i=0;i<n;i++){
             
       while(!s2.empty()&&arr[s2.top()]>arr[i])
        {
           s2.pop();
        };
  
   if(!s2.empty()){
      v2[i] = i - s2.top() - 1;
   }
   else{
      v2[i]=i;
   }
   s2.push(i);
    }
      for(int i=0;i<n;i++){
          sum = (sum + (long long)arr[i] * (v1[i]+1) * (v2[i]+1)) % MODULO;
      } 
             return sum;
    }
};