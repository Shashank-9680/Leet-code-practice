class Solution {
public:
    bool isCircularSentence(string sentence) {
      stringstream ss(sentence);
        string word;
        vector<string> words;
         while (ss >> word) {
        words.push_back(word);
    }
        vector<char>v;
        for(auto it:words){
            v.push_back(it[0]);
            v.push_back(it[it.size()-1]);
        }
       
        for(int i=1;i<v.size()-1;i+=2){
            if(i==v.size()-1){
                break;
            }
            if(v[i]!=v[i+1]){
                return false;
            }
        }
        if(v[0]!=v[v.size()-1]){
            return false;
        }
        return true;
    }
};