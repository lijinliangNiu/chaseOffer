class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int zero_num = 0;
        while(nums[zero_num] == 0){
            zero_num++;
        }
        for(int i = zero_num; i < 4; i++){
            if(nums[i] == nums[i + 1]){
                return false;
            }
        }
        return nums[4] - nums[zero_num] < 5; 
    }
};