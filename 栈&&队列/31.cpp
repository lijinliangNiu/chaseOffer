class Solution {
   public:
    //本来想着后撤，但最好不要动pushed内部的值吧，只有用栈辅助了
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j = 0;
        for (auto x : pushed) {
            s.push(x);
            while (!s.empty() && s.top() == popped[j]) {
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};