class myQueue {
  queue<int>q;
  int count;
  public:
    myQueue(int n) {
        count=n;
    }

    bool isEmpty() {
       if(q.size()==0) return true;
       return false;
    }

    bool isFull() {
       if(q.size()==count) return true;
       return false;
    }

    void enqueue(int x) {
      if(q.size()!=count){
          q.push(x);
      }
    }

    void dequeue() {
       if(q.size()!=0){
           q.pop();
       }
    }

    int getFront() {
        if(q.size()!=0){
            return q.front();
        }
        return -1;
    }

    int getRear() {
       if(q.size()!=0){
           return q.back();
       }
       return -1;
    }
};