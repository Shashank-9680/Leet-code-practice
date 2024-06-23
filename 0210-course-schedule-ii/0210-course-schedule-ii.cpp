class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          int n=prerequisites.size();
     vector<int>adj[numCourses];
        vector<int>indegree(numCourses,0);
        for(int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int prereq = prerequisites[i][1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        queue<int>q;
       


vector<int>result;
for(int i=0;i<numCourses;i++){
    if(indegree[i]==0){
        q.push(i);
    }
}
while(!q.empty()){
   int value=q.front();
   q.pop();
   result.push_back(value);
   for(auto it:adj[value]){
       indegree[it]--;
       if(indegree[it]==0){
           q.push(it);
       }
   }
}
        if(result.size()==numCourses) return result;
        return {}; 
    }
};