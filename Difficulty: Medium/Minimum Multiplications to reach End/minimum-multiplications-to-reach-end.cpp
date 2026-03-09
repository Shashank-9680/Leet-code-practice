class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {

        const int MOD = 100000;
        vector<int> dist(100000, 1e9);

        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while(!pq.empty()){
            auto [step,node] = pq.top();
            pq.pop();

            if(node == end) return step;

            for(int i=0;i<arr.size();i++){
                int product = (node * arr[i]) % MOD;

                if(step + 1 < dist[product]){
                    dist[product] = step + 1;
                    pq.push({dist[product], product});
                }
            }
        }

        return -1;
    }
};