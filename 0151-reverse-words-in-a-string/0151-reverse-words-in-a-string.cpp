class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int n=s.size();
        vector<string>ans;
        while(i<n){
            while(i<n&& s[i]==' '){
                i++;
            }
            if(i==n) break;
            int j=i;
            while(i<n&&s[i]!=' '){
                i++;
            }
            ans.push_back(s.substr(j,i-j));
        }

        reverse(ans.begin(),ans.end());
        string word="";
        n=ans.size();
        for(int i=0;i<n;i++){
           word+=ans[i];
           if(i!=n-1){
            word+=" ";
           }
        }
        return word;

    }
};