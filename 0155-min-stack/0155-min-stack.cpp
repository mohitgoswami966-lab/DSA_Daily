class MinStack {
    stack<long long> s;
    long long mini;
public:
    MinStack() {}
    
    void push(int value) {
        if(s.empty()){
            s.push(value);
            mini=value;
        }
        else{
            if(value<mini){
                s.push(2LL*value-mini);
                mini=value;
            }
            else{
                s.push(value);
            }
        }
    }
    
    void pop() {
        if(s.empty()) return;
        long long curr=s.top();
        if(curr<mini){
            mini=2*mini-curr;
        }
        s.pop();
    }
    
    int top() {
        if(s.empty()) return -1;
        long long curr=s.top();
        if(curr<mini) return mini;
        else return curr;
    }
    
    int getMin() {
        if(s.empty()) return -1;
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */