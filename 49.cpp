/*
一开始丑数只有{1}，1可以同2，3，5相乘，取最小的1×2=2添加到丑数序列中，1失去了同2相乘的资格。
现在1有与3，5相乘的资格，2有与2，3，5相乘的资格，但是2×3和2×5是没必要比较的，因为有比它更小的1可以同3，5相乘，所以我们只需要比较1×3，1×5，2×2。 
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int l2 = 0, l3 = 0, l5 = 0;
        for(int i = 1; i < n; ++i) {
            dp[i] = min(min(dp[l2] * 2, dp[l3] * 3), dp[l5] * 5);
            if (dp[i] == dp[l2] * 2) {
                ++l2;
            }
            if (dp[i] == dp[l3] * 3) {
                ++l3;
            } 
            if (dp[i] == dp[l5] * 5) {
                ++l5;
            }
        }
        return dp[n - 1];
    }
};