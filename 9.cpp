class CQueue {
private:
    stack<int> in, out;
public:
    CQueue(){
    }
    
    void appendTail(int value) {
        in.push(value);
    }
    
    //两个栈实现一个队列，一个负责进，一个负责出
    //出栈空了再把进栈倒进去
    int deleteHead() {
        int head = -1;
        if(out.empty()){      
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
        if(!out.empty()){
            head = out.top();
            out.pop();
        }
        return head;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */