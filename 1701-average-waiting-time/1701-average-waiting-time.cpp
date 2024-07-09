class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
      
      
        long long int sum=customers[0][0]+customers[0][1];
        
        long long int total=sum-customers[0][0];
        for(int i=1;i<n;i++){
            
              
                if(sum>=customers[i][0]){
                sum=sum+customers[i][1];     
                }
                else{
                    sum=(customers[i][1]+customers[i][0]);
                }
                total=total+(sum-customers[i][0]); 
               
            
        }
        return (double)total/n;
        
    }
};