class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size() - 1;
        while(left < right){
            int mid = (left + right) / 2;
            //和left比较无法确定mid属于哪一部分
            if(numbers[mid] == numbers[right]){
                //这一块比较精妙
                right--;
            }
            else if(numbers[mid] > numbers[right]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return numbers[left];
    }
};