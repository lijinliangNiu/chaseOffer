class Solution {
private:
    int searchLowerBound(vector<int>& nums, int target){
        int l = 0, r = nums.size();
        while(l < r){
            int mid = (l + r) / 2;
            if(nums[mid] >= target){// =让这个可以找到第一个数
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
    int searchUpperBound(vector<int>& nums, int target){
        int l = 0, r = nums.size();
        while(l < r){
            int mid = (l + r) / 2;
            if(nums[mid] > target){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
public:
    int search(vector<int>& nums, int target) {
        int low_bound = searchLowerBound(nums, target);
        if(low_bound == nums.size() || nums[low_bound] != target){
            return 0;
        }
        return searchUpperBound(nums, target) - low_bound;
    }
};