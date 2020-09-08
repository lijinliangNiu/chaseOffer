class Solution {
private:
    int random_partition(vector<int>& arr, int l, int r){
        swap(arr[r], arr[l + rand() % (r - l + 1)]);
        int pivot = arr[r];
        int i = l;//待交换位置
        for(int j = l; j < r; j++){
            if(arr[j] <= pivot){
                swap(arr[i++], arr[j]);
            }
        }
        swap(arr[i], arr[r]);
        return i;
    }
    void random_select(vector<int>& arr, int l, int r, int k){
        if(l >= r){
            return;
        }
        int pos = random_partition(arr, l, r);
        int least_num = pos - l + 1;
        if(least_num == k){
            return;
        }
        else if(least_num < k){
            random_select(arr, pos + 1, r, k - least_num);
        }
        else{
            random_select(arr, l, pos - 1, k);
        }
    }
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans;
        srand((unsigned)time(NULL));
        random_select(arr, 0, (int)arr.size() - 1, k);
        for(int i = 0; i < k; i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};