class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>m;
        if(hand.size()%groupSize!=0){
            return false;
        }
        for(auto &value:hand){
            m[value]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(auto values:m){
        pq.push({values.first,values.second});
        
    }
   
     while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

           
            if (m[it.first] == 0) continue;

            int count = m[it.first];

          
            for (int i = 0; i < groupSize; ++i) {
                int card = it.first + i;
                if (m[card] < count) {
                    return false; 
                }
                m[card] -= count;

               
                if (m[card] > 0) {
                    pq.push({card, m[card]});
                }
            }
        }

        return true; 
      
    }
    
};