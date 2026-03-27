class Solution {
public:
    string reverseWords(string s) {
        vector<string>ans;
        int i=0;
        int n=s.size();

        while(i<n){
            while(i<n&&s[i]==' '){
                i++;
            }
            int j=i;
            if(i==n) break;
            while(i<n&&s[i]!=' '){
                i++;
            }
            string temp="";
            temp+=s.substr(j,i-j);
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        for(auto it:ans){
            cout<<it;
        }
        string result="";
        int a=ans.size();
        for(int i=0;i<ans.size();i++){
            result+=ans[i];
            if(i!=a-1){
                result+=" ";
            }
        }
        return result;
    }
};