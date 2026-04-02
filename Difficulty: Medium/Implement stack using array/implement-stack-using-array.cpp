class myStack {
  public:
  int count=0;
   stack<int>st;
    myStack(int n) {
        count=n;
    }

    bool isEmpty() {
        if(st.size()==0) return true;
        return false;
    }

    bool isFull() {
       if(st.size()==count) return true;
       return false;
    }

    void push(int x) {
        if(st.size()!=count){
            st.push(x);
        }
    }

    void pop() {
        if(st.size()!=0){
            st.pop();
        }
        
    }

    int peek() {
        if(st.empty()){
            return -1;
        }
     int top_element=st.top();
     return top_element;
    }
};