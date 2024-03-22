class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
         map <long long,int> m;
        
long long psum=0;
int count=0;
  for(int i=0;i<a.size();i++){
     psum+=a[i];
     if(psum==k){
        count++;
     }
    long long int rem=psum-k;
     if(m.find(rem)!=m.end()){
       count=count+m[rem];
     }
      if(m.find(psum)!=m.end()){
               m[psum]++;
           }
           else{
              m[psum]=1;
           }
    
  }
  return count;
  
    }
};