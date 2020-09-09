class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) {
            return 0;
        }
        if(s.size()==1) {
            return 1;
        }
        //滑窗，如果有重复，l直接右移较远位置
        unordered_map<char, int> last_pos;
        int l = 0, ans = 0;
        for(int r = 0; r < s.size(); r++){
            if(last_pos.find(s[r]) != last_pos.end()) {
                l = max(last_pos[s[r]], l);
            }
            last_pos[s[r]] = r + 1;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};