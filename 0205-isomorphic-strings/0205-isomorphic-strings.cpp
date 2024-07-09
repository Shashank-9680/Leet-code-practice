class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m) return false;
       unordered_map<char,char>a;
        unordered_map<char,char>b;
       for(int i=0;i<n;i++){
           a[s[i]] = t[i];
            b[t[i]] = s[i];
       }
        
        for(int i=0;i<n;i++){
            if ((a[s[i]] != t[i]) || (b[t[i]] != s[i])) {
                return false;
            }
            
        }
        return true;
    }
};