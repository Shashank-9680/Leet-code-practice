class Solution {
public:
    string breakPalindrome(string s) {
        int n=s.size();
        if(n<=1)return "";    //if size is 1 , then it is always a palindrome
        for(int i=0;i<n/2;++i){
            if(s[i]!='a'){  //replace the first non 'a' character
                s[i]='a';
                return s;
            }
        }
        s.pop_back();  //if the string is all a's => "aaaaa", then replace the last character with 'b'
        s+='b';
        return s;
    }
};