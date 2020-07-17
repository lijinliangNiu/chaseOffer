class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        if(nums.size() <= 0){
            return -1;
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0 || nums[i] > nums.size() -1){
                return -1;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            while(nums[i] != i){
                if(nums[i] == nums[nums[i]]){
                    return nums[i];
                }
                swap(nums[i], nums[nums[i]]);
            }
        }  
        return -1; 
    }
};