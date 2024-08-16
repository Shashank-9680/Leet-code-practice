class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m=arrays.size();
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int maxi1=INT_MIN;
        int mini1=INT_MAX;
        int index1=-1;
        int index2=-1;
       for(int i=0;i<m;i++){
           int size=arrays[i].size();
           if(arrays[i][size-1]>maxi){
               maxi=arrays[i][size-1];
               index1=i;
           }
           
          
       } 
        // cout<<maxi;
        for(int i=0;i<m;i++){
            if(arrays[i][0]<mini){
            mini=arrays[i][0];   
                index2=i;
            }
        }    
        if(index1!=index2){
            return abs(maxi-mini);
        } 
          for(int i=0;i<m;i++){
           int size=arrays[i].size();
              if(index1==i){
                  continue;
              }
           if(arrays[i][size-1]>maxi1){
               maxi1=arrays[i][size-1];
               
           }
           
          
       } 
        
        for(int i=0;i<m;i++){
            if(index1==i){
                continue;
            }
            if(arrays[i][0]<mini1){
             mini1=arrays[i][0];   
                index2=i;
            }
        }     
        // cout<<maxi1<<mini1;
      int diff1=abs(maxi-mini1);
        int diff2=abs(maxi1-mini);
        return max(diff1,diff2);
        // return 0;
        
    }
};