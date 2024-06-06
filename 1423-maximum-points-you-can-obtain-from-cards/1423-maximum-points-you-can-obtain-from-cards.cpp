class Solution {
public:
    int maxScore(vector<int>& a, int k) {
     int leftsum=0;
        int rightsum=0;
        int n=a.size();
        for(int i=0;i<k;i++){
            leftsum=leftsum+a[i];
        }
        int maxsum=leftsum;
        int rightindex=n-1;
        for(int i=k-1;i>=0;i--){
            leftsum=leftsum-a[i];
            rightsum=rightsum+a[rightindex];
            rightindex--;
             maxsum=max(maxsum,leftsum+rightsum);
        }
       
        return maxsum;
    }
};