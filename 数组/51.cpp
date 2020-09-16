class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());
        return mergeSort(nums, 0, nums.size() - 1, temp);
    }

private:
    int mergeSort(vector<int>& nums, int begin, int end, vector<int>& temp) {
        if (begin < end) {
            int mid = (begin + end) / 2;
            int ans = mergeSort(nums, begin, mid, temp) + mergeSort(nums, mid + 1, end, temp);

            int i = begin;
            int j = mid + 1;
            for (int k = 0; k <= end - begin; k++) {
                if (i <= mid && (j > end || nums[i] <= nums[j])) {
                    temp[k] = nums[i++];
                    ans += (j - mid - 1);
                } 
                else {
                    temp[k] = nums[j++];
                }
            }

            memcpy(&nums[begin], &temp[0], (end - begin + 1) * sizeof(int));
            return ans;
        }
        return 0;
    }
};