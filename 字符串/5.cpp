class Solution {
public:
    string replaceSpace(string s) {
        if(s.length() <= 0){
            return s;
        }
        int blank_num = 0;
        for(auto ch:s){
            if(ch == ' '){
                blank_num++;
            }
        }
        int p_ori = s.length() - 1;
        s += string(2 * blank_num, ' ');
        int p_new = s.length() - 1;
        while(p_ori >= 0 && p_new > p_ori){
            if(s[p_ori] != ' '){
                s[p_new--] = s[p_ori--];
            }
            else{
                s[p_new--] = '0';
                s[p_new--] = '2';
                s[p_new--] = '%';
                p_ori--;
            }
        }
        return s;
    }
};