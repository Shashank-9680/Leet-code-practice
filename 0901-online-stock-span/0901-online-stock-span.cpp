class StockSpanner {
     int count;
    vector<int> arr;
    stack<int> s;
public:
    
    StockSpanner() {     
     count=0;
    }
    
    int next(int price) {
       
        arr.push_back(price);
        while (!s.empty() && arr[s.top()] <= price) {
            s.pop();
        }
        int result = (s.empty()) ? count + 1 : count - s.top();
        s.push(count);
        count++;
        return result;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */