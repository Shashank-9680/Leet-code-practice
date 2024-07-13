class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      queue<pair<string,int>>q;
        unordered_set<string>s(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        s.erase(beginWord);
        while(!q.empty()){
            string intial=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(intial==endWord){
                return steps;
            }
            for(int i=0;i<intial.size();i++){
                char orignal=intial[i];
                for(char ch='a';ch<='z';ch++){
                    intial[i]=ch;
                    if(s.find(intial)!=s.end()){
                        s.erase(intial);
                        q.push({intial,steps+1});
                    }
                    
                }
                intial[i]=orignal;
                
            }
        }
        return 0;
    }
};