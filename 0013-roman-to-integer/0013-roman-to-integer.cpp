class Solution {
    int value(char a){
        if(a=='I'){
            return 1;
        }
        else if(a=='V'){
            return 5;
            
        }
        else if(a=='X'){
            return 10;
        }
          else if(a=='L'){
            return 50;
        }
          else if(a=='C'){
            return 100;
        }
          else if(a=='D'){
            return 500;
        }
          else if(a=='M'){
            return 1000;
        }
    return -1;
    }
public:
    int romanToInt(string s) {
         unordered_map<char, int> m;
        
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(m[s[i]] < m[s[i+1]]){
                ans -= m[s[i]];
            }
            else{
                ans += m[s[i]];
            }
        }
        return ans;
       
    }
};