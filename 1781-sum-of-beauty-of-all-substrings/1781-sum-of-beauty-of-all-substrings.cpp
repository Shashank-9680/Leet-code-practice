class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
             vector<int>v(26,0);
            for(int j=i;j<s.size();j++){
                int a=s[j]-'a';
                v[a]++;
                int mini=INT_MAX;
                int maxi=INT_MIN;
                for(int i=0;i<26;i++){
                    if(v[i]!=0){
                     mini=min(v[i],mini);
                     maxi=max(v[i],maxi);
                    }
                }
                sum+=abs(maxi-mini);
            }
        }
        return sum;
    }
};