class Solution {
private:
    mt19937 gen{random_device{}()};

    void random_select(vector<int>& arr, int left, int right, int k){
        swap(arr[right], arr[uniform_int_distribution<int>{left, right}(gen)]);//arr[r]就是pivot
        int i = left; //待交换位置
        for(int j = left; j < right; j++){
            if(arr[j] <= arr[right]){
                swap(arr[i++], arr[j]);
            }
        }
        swap(arr[i], arr[right]);//pivot归位
        int less_num = i - left + 1;
        if(less_num == k){
            return;
        }
        else if(less_num > k){
            random_select(arr, left, i - 1, k);
        }
        else{
            random_select(arr, i + 1, right, k - less_num);
        }
    }
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k == 0){
            return {};
        }
        random_select(arr, 0, arr.size() - 1, k);
        return {arr.begin(), arr.begin() + k};
    }
};