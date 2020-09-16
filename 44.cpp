class Solution {
public:
    int findNthDigit(int n) {
        int digit_num = 1;//数字有几位
        for(long base = 9; n - base * digit_num > 0; base *= 10){
            n -= base * digit_num;//经过计算，n为数字在具有这些位的数字中的第几个
            digit_num++;
        }

        int number = pow(10, digit_num - 1) + n / digit_num;//落到的数字
        int index = n % digit_num;//落在number中的哪一位
        if(index == 0){//上个number的末位
            number -= 1;
            index = digit_num;
        }
        
        //取number的第index个数字，把这一位除到个位，然后求余
        for (int i = index; i < digit_num; i++) {
            number /= 10;
        }
        return number % 10;
    }
};