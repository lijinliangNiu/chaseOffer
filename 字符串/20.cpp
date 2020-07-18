class Solution {
private:
    int index = 0;

    bool isInt(string& s) {  // 判断有符号整数
        if (index < s.size() && (s[index] == '-' || s[index] == '+')) {
            index++;
        }
        return isUnsigned(s);
    }

    bool isUnsigned(string& s) {  // 判断无符号整数
        int pre = index;
        for (; index < s.size(); index++) {
            if (s[index] < '0' || s[index] > '9') {
                break;
            }
        }
        return index > pre;
    }

    void removeBlank(string& s){
        for(; index < s.size() && s[index] == ' '; index++){
            ;
        }
    }

public:
    bool isNumber(string s) {
        if (s.empty()) {
            return false;
        }
        removeBlank(s);
        bool ans = isInt(s);
        if (index < s.size() && s[index] == '.') {
            index++;
            ans = isUnsigned(s) || ans;  // 如果有小数点，前后都没有数字才不对
        }
        if (index < s.size() && s[index] == 'e') {
            index++;
            ans = isInt(s) && ans;  // 如果出现e，则e前后必须有整数
        }
        removeBlank(s);
        return ans && index == s.size();
    }
};