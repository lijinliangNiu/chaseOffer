class MinStack {
private:
    stack<int> s;
    int minimum = INT_MAX;

public:
    MinStack() {
    }
    
    void push(int x) {
        if(x <= minimum){ //=很关键
            s.push(minimum);
            minimum = x;
        }
        s.push(x);
    }
    
    void pop() {
        if(s.top() == minimum){
            s.pop();
            minimum = s.top();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return this->minimum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */