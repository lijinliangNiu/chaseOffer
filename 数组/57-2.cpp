class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        for(int l = 1, r = 2; l < r;){
            int sum = (l + r) * (r - l + 1) / 2;
            if(sum == target){
                vector<int> temp;
                for(int i = l; i <= r; i++){
                    temp.emplace_back(i);
                }
                ans.emplace_back(temp);
                l++;
            }
            else if(sum < target){
                r++;
            }
            else{
                l++;
            }
        }
        return ans;
    }
};