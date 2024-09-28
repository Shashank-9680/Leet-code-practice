class MyCalendar {
public:
  vector<pair<int,int>>events;
    int count=0;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
       for (auto event : events) {
            
            int eventStart = event.first;
            int eventEnd = event.second;
            if (start < eventEnd && eventStart < end) {
               
                return false;
            }
        }
        // No overlap, add the new event to the calendar
        events.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */