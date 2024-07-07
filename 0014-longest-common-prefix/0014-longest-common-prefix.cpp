class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
       sort(strs.begin(),strs.end()); 
        int i=-1;
      
        int a=strs[0].size();
        string s1=strs[0];
        string s2=strs[n-1];
        int b=strs[n-1].size();
        while(i<a&&i<b){
            i++;
            if(s1[i]!=s2[i]){
               break; 
            }
            
        }
        if(i==-1){
            return "";
        }
       
            string s=s1.substr(0,i);
        return s;
        
    }
};