class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int len=0;
        string ans;
        for(int i=0;i<n;i++){
            int a=i;
            int b=i;
            while(a>=0&&b<n&&s[a]==s[b]){
               int length=b-a+1;
               if(length>len){
                   len=length;
                   ans= s.substr(a,length);
               }
               a--;
               b++;
            }
        }
            
            for(int i=0;i<n-1;i++){
            int a=i;
            int b=i+1;
            while(a>=0&&b<n&&s[a]==s[b]){
               int length=b-a+1;
               if(length>len){
                   len=length;
                   ans= s.substr(a,length);
               }
               a--;
               b++;
            }
        }

        
        return ans;
    }
};