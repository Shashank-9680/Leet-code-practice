class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
   int count1=0;
        int count2=0;
       
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                count1++;
            }
            else if(bills[i]==10){
                if(count1==0){
                    return false;
                }
                count1--;
                count2++;
            }
             else if(bills[i]==20){
               if((count2==0&&count1*5<15)||count1==0){
                  return false; 
               }
                 else if(count1*5>=5&&count2!=0){
                     count2--;
                     count1--;
                 }
                 else if(count2==0){
                     count1=count1-3;       
                 }
                
                 
            }
        }
        return true;
    }
};