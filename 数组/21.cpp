class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        for(int pos = 0, num = 0; num < nums.size(); num++){
            if(nums[num] & 1){
                swap(nums[pos], nums[num]);
                pos++;
            }
        }
        return nums;
    }
};