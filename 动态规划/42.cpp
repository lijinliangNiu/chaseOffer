class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, ans = nums[0];
        for(const auto& num : nums){
            //要不要前边的累和
            pre = max(pre + num, num);
            ans = max(ans, pre);
        }
        return ans;
    }
};