class Solution {
public:
    bool isPalindrome(int x) {
        int c=0;
       if(x<0){
           return false;
       } 
       else{
           vector<int> v;
          while(x>0){
         v.push_back(x%10);
           x=x/10;
          }
         int n=v.size();
          for(int i=0;i<n;i++){
              if(v[i]!=v[n-1-i]){
              c=1;
              }
          }
       
            if(c==1){
               return false;
            }
            else{
                return true;
            }
       


       }
    }
};