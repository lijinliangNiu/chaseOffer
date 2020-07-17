class Solution {
public:
    bool isMatch(string s, string p) {
        auto matches = [&](int i, int j) {
            if (i == 0) { //j=0不用计算
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        //0只是辅助
        vector<vector<int> > opt(s.size() + 1, vector<int>(p.size() + 1));
        opt[0][0] = true;
        for(int i = 0; i <= s.size(); i++){
            for(int j = 1; j <= p.size(); j++){//模式串长为0，没必要考虑，dp时也用不到
                if(p[j - 1] == '*'){
                    opt[i][j] = opt[i][j - 2];
                    if(matches(i, j - 1)){
                        opt[i][j] |= opt[i - 1][j];
                    }
                }
                else{
                    if(matches(i, j)){
                        opt[i][j] = opt[i - 1][j - 1];
                    }
                }
            }
        }
        return opt[s.size()][p.size()];
    }
};