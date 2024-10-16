class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        string ans = "";
        
        while (!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int value = it.first;
            char ch = it.second;
            
           
            if (ans.size() >= 2 && ans[ans.size() - 1] == ch && ans[ans.size() - 2] == ch) {
                // If pq is empty, break as no valid moves left
                if (pq.empty()) break;
                
                auto val = pq.top(); pq.pop();
                ans += val.second;
                if (val.first - 1 > 0) pq.push({val.first - 1, val.second});
                
                pq.push({value, ch}); // Push 'ch' back into the pq
            } else {
                ans += ch;
                if (--value > 0) pq.push({value, ch}); // Only push if count > 0
            }
        }
        
        return ans;
    }
};
