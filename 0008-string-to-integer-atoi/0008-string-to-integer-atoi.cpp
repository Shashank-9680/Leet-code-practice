class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        int sign=1;
        while(i<n && s[i]==' ') i++;
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+'){
            sign=1;
            i++;
        }
        while(i<n&&s[i]=='0') i++;
        int ans=0;
        while(i<n&&isdigit(s[i])){
           int val=s[i]-'0';

           if(ans>(INT_MAX-val)/10){
              if(sign==-1){
                return INT_MIN;
              }
              else{
                return INT_MAX;
              }

           }
           ans=ans*10+val;
           i++;
        }
        
        if(sign<0) return -ans;
        return ans;


    }
};