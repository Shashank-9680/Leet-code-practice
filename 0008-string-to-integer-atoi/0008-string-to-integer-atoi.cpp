class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        int sign=1;
        int result=0;
        while(i<n&& s[i]==' ') i++;
        if(i==n) return 0;
        if(s[i]=='-'){
            i++;
            sign=-1;
        }
        else if(s[i]=='+'){
            i++;
            sign=1;
        }
        while(i<n&& s[i]=='0') i++;
        while(i<n && isdigit(s[i])){
            int val=s[i]-'0';
            if(result>(INT_MAX-val)/10){
                if(sign==1){
                    return INT_MAX;
                }
                return INT_MIN;
            }
            result= result*10+val;
            i++;
        }
        if(sign==1) return result;
        return -result;
    }
};