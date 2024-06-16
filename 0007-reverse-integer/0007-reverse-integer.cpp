class Solution {
public:
    int reverse(int x) {
      
        int ans=0;
        int flag=0;
        if(x<0){
            flag=1;
        }
        
        int y=abs(x);
        
        while(y>0){
            int a=y%10;
            y=y/10;
           if (ans > (INT_MAX - a) / 10) {
                return 0;
            }
            ans=ans*10+a;
            
        }
         
        if(flag==1){
            return -ans;
        }
        return ans;
    }
};