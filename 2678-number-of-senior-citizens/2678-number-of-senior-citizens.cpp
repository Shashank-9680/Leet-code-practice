class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(int i=0;i<details.size();i++){
            string s=details[i];
            string a=s.substr(11,2);
            if(stoi(a)>60){
              count++;  
            }
        }
        return count;
    }
};