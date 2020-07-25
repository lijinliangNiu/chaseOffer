class Solution {
   public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.empty()) {
            return true;
        }
        return verifyPostorder(postorder, 0, postorder.size() - 1);
    }
    bool verifyPostorder(vector<int>& postorder, int left, int right) {
        if (left >= right) {//空树取大于
            return true;
        }
        int mid = left;
        for (; mid <= right; mid++) {
            if (postorder[mid] >= postorder[right]) {
                break;
            }
        }
        for (int i = mid; i <= right; i++) {
            if (postorder[i] < postorder[right]) {
                return false;
            }
        }
        return verifyPostorder(postorder, left, mid - 1) &&
               verifyPostorder(postorder, mid, right - 1);
    }
};