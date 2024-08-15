class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int twenty=0;
        int ten=0;
        if(bills[0]>5){
           return false; 
        }
        for(int i=0;i<bills.size();i++){
           if(bills[i]==5){
               five++;
           }
            
            if(bills[i]==10){
                if(five==0){
                    return false;
                }
                ten++;
                five--;
            }
            if(bills[i]==20){
                if(five*5<15&&ten==0){
                    return false;
                }
                if(five==0){
                    return false;
                }
               if(ten==0){
                   five=five-3;     
               }
               else if(ten>=1&&five>=1){
                five--;
                ten--;
            }
                
            }
            
        }
        return true;
    }
};