class MyQueue {
public:
    stack<int> in;
    stack<int> out;
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if(out.empty()){
            while(!in.empty()){
                int ans=in.top();
                in.pop();
                out.push(ans);
            }
        }
        int ans=out.top();
        out.pop();
        return ans;
    }
    
    int peek() {
        if(out.empty()){
            while(!in.empty()){
                int ans=in.top();
                in.pop();
                out.push(ans);
            }
        }
        int ans=out.top();
        return ans;
    }
    
    bool empty() {
        return (in.empty() and out.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */