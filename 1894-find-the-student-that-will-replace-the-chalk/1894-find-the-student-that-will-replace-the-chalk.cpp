class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum=0;
        for(long long int i=0;i<chalk.size();i++){
            sum+=chalk[i];
        }
         k = k % sum;
       
        if(k==0){
            return 0;
        }
        cout<<k;
        for(long long int i=0;i<chalk.size();i++){
            if(k<chalk[i]){
                return i;
                break;
                }
            k=k-chalk[i];
        }
        return -1;
    }
};