class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>m;
        int length=0;
        int i=0;
        int j=0;
        int n=s.size();
       while(j<n){
           
            if (m.find(s[j]) != m.end()) {
                i = max(i, m[s[j]] + 1);
            }
            length=max(length,j-i+1);
           m[s[j]]=j;
            j++;
         
        }
        return length;
    }
};