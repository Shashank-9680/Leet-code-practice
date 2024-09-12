class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count=0;
        unordered_map<char,int>m;
         for(auto it:allowed){
             m[it]++;
         }
     for(auto word:words){
         bool flag=false;   
         for(auto it:word){
             if(m.find(it)==m.end()){
                 flag=true;
             }
         }
         if(!flag){
             count++;
         }    
     }
        return count;
    }
};