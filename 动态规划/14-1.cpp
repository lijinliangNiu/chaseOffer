class Solution {
public:
    int cuttingRope(int n){
        if(n < 2){
            return 0;
        }
        if(n == 2){
            return 1;
        }
        if(n == 3){
            return 2;
        }
        vector<int> dp(n + 1, 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;//注意dp和实际不同 why？因为至少要切成2段，但dp中可以单独出现
        for(int i = 4; i <= n; i++){
            for(int j = 1; j <= i / 2;j++){
                if(dp[j] * dp[i-j] > dp[i]){
                    dp[i] = dp[j] * dp[i-j];
                }
            }
        }
        return dp[n];
    }
};