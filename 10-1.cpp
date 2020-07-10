class Solution {
public:
    int fib(int n) {
        if(n == 0){
            return 0;
        }
        else if(n == 1){
            return 1;
        }
        else{
            int pre2 = 0;
            int pre1 = 1;
            int current = 1;
            for(int i = 2; i <= n; i++){
                current = (pre1 + pre2) % 1000000007;
                pre2 = pre1;
                pre1 = current;
            }
            return current;
        }
    }
};