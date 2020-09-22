class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int length = a.size();
        vector<int> b(length, 1);
        int left = 1, right = 1;
        for(int i = 0; i < length; i++){
            b[i] *= left;
            left *= a[i];

            b[length - 1 - i] *= right;
            right *= a[length - 1 - i];
        }
        return b;
    }
};