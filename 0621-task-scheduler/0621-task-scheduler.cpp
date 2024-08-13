class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
      vector<int>hash(26,0);
        for(int i=0;i<tasks.size();i++){
            hash[tasks[i]-'A']++;
        }
        priority_queue<int>pq;
        for(int i=0;i<26;i++){
            if(hash[i]>0){
                pq.push(hash[i]);
            }
        }
        queue<pair<int,int>>q;
        int time=0;
        while(!pq.empty()||!q.empty()){
            if(!q.empty()&&q.front().second+n<time){
                  pq.push(q.front().first);
                  q.pop();
            }
            if(!pq.empty()){
                int node=pq.top();
                pq.pop();
                if(node>1){
                q.push({node-1,time});    
                }
                
            }
            time++;
        }
        return time;
        
    }
};