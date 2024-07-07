class Solution {
  
public:
    string largestOddNumber(string num) {
       int n=num.size();
        int j=-1;
        for(int i=n-1;i>=0;i--){
            if((num[i] - '0') % 2 != 0){
                j=i;
                break;
            }
        }
       
        if(j==-1){
            return "";
        }
        string s=num.substr(0,j+1);
        return s;
    }
};