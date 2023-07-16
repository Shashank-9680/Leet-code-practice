class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       int n=matrix.size();
        int k=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
              int t=matrix[i][j];
                    matrix[i][j]=matrix[j][i];
                matrix[j][i]=t;
            }
           
        }
        int low=0;int high=n-1;
        while(low<=high){
           for(int i=0;i<n;i++){
               int temp= matrix[i][low];
               matrix[i][low]=matrix[i][high];
               matrix[i][high]=temp;
           } 
            high--;
            low++;
        }
        
    }
};