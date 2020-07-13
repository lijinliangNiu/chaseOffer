class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1 || n == 0){
            return 1;
        }
        long pow = n;
        if(n < 0){
            pow = -pow;
            x = 1 / x;
        }
        double ans = 1;
        while(pow){
            if(pow & 1){
                ans *= x;
            }
            x *= x;
            pow >>= 1;
        }
        return ans;
    }
};