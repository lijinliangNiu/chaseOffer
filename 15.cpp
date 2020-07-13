class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n){
            ans++;
            n = (n - 1) & n;//最右边的1变成0
        }
        return ans;
    }
};