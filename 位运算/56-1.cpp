class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ret = 0;
        for(auto& num : nums){
            ret ^= num;
        }
        int mask = 1;
        while((ret & mask) == 0){
            mask <<= 1;
        }
        int a = 0, b = 0;
        for(auto& num : nums){
            if((num & mask) == 0){
                a ^= num;
            }
            else{
                b ^= num;
            }
        }
        return {a, b};
    }
};