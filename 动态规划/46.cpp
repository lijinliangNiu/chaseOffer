class Solution {
public:
    int translateNum(int num) {
        int p = 0, q = 0, r = 1;
        for(int i = 0; i < to_string(num).size(); i++){
            p = q;            
            q = r;
            if(i == 0) {
                continue;
            }
            if(to_string(num).substr(i - 1, 2) <= "25" && to_string(num)[i - 1] != '0'){
                r = p + q;
            }
        }
        return r;
    }
};