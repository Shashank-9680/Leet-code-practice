class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int close=0;
        for(auto it:s){
          if(it=='('){
              open++;
          }
         else{
             if(open<=0){
                 close++;
             }
             else{
                 open--;
             }
         }
        }
       
       return abs(open+close);
    }
};