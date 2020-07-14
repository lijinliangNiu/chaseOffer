class Solution {
public:
    vector<int> res;
    vector<int> printNumbers(int n) {
        if(n <= 0) {
            return res;
        }
        string number(n, '0');
        for(int i = 0;i <= 9;i++){
            number[0] = i + '0';
            permutionNum(number, n, 1);
        }
        return res;
    }

    void permutionNum(string &number, int length, int index){
        if(index == length){
            saveNum(number);
            return;
        }
        else{
            for(int i=0; i<10; i++){
                number[index] = '0' + i;
                permutionNum(number, length, index+1);
            }
        }
    }
    void saveNum(string number){
        string tempStr(number.size(),'0');
        if(number != tempStr) {
            res.push_back(stoi(number));
        }
    }
};