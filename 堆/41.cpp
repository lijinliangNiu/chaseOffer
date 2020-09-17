class MedianFinder {
private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(left.size() == right.size()){
            left.push(num);
            right.push(left.top());
            left.pop();
        }
        else{
            right.push(num);
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() == right.size()){
            return (left.top() + right.top()) / 2.0;
        }
        else{
            return right.top();
        }
    }
};