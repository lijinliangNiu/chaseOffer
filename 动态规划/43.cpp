class Solution {
private:
    int digit[11] = {0};//n的倒序的每位数字
    int dp[11][11];

    //位可搜索范围会不一样，用limit判定
    //假设搜索范围位[0, 555]
    //最高位取到4时，下一位无限制；最高位取到5时，下一位也被限制，即limit && (i == max)

    //假设更低位的都准备好了
    int dfs(int pos, int count, bool limit){
        if(pos == 0){
            return count;
        }
        if(!limit && dp[pos][count]!= -1){
            return dp[pos][count];
        }
        int res = 0;
        int max = limit ? digit[pos] : 9;
        for(int i = 0; i <= max; i++){
            res += dfs(pos - 1, count + (i == 1), limit && (i == max));
        }
        if(!limit){
            dp[pos][count] = res;
        }
        return res;
    }
public:
    int countDigitOne(int n ){
        if(n <= 0){
            return 0;
        }
        else{
            memset(dp, -1, sizeof(dp));
            int len = 0;

            for(; n > 0; n /= 10){
                digit[++len] = n % 10;
            }
            return dfs(len, 0, true);
        }
    }
};