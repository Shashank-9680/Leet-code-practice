class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix[0].size();
        int m=matrix.size();
        int flag=0;
        int index;
        for(int i=0;i<m;i++){
            if(matrix[i][0]<=target&& matrix[i][n-1]>=target){
                flag=1;
                index=i;
                break;
            }
        }
        if(flag==0){
            return false;
        }
        else{
            int low=0;
            int high=n-1;
            while(high>=low){
               int mid=(high+low)/2;
                if(matrix[index][mid]==target){
                    return true;
                }
                else if(matrix[index][mid]>target){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            return false;
        }
    }
};