class Solution {
public:
    int numWays(int n) {
        if(n <= 1){
            return 1;
        }
        else{
            int pre2 = 1;
            int pre1 = 1;
            int current = 2;
            for(int i = 2; i <= n; i++){
                current = (pre1 + pre2) % 1000000007;
                pre2 = pre1;
                pre1 = current;
            }
            return current;
        }
    }
};