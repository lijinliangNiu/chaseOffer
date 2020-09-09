class Solution {
public:
    char firstUniqChar(string s) {
        if(s == ""){
            return ' ';
        }
        unordered_map<char, int> cmap;
        for(auto i = 0; i < s.size(); i++){
            cmap[s[i]]++;
        }
        for(auto i = 0; i < s.size(); i++){
            if(cmap[s[i]] == 1){
                return s[i];
            }
        }
        return ' ';
    }
};