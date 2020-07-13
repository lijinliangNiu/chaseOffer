/*
14-1使用dp，但因为此题要求模，故仍需要贪心，依靠基本不等式可知
要尽可能多的分割出3，且2 * 2 > 3 * 1，代码如下。
*/
class Solution {
public:
    int cuttingRope(int n) {
        if(n == 2) {
            return 1;
        }
        if(n == 3){
            return 2;
        }
        long ans = 1;
        while(n > 4){//4可以避免3*1置换成2*2
            ans *= 3; //还是会溢出int
            ans %= 1000000007;
            n -= 3;
        }
        return (int)((ans * n) % 1000000007);
    }
};