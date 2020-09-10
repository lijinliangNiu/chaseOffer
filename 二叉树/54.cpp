//二叉搜索树中序遍历为递增序列，反向中序遍历就可了
class Solution {
private:
    int ans;
    void dfs(TreeNode* root, int& k){
        if(root == nullptr){
            return;
        }
        dfs(root->right, k);
        if(k-- == 1){
            ans = root->val;
        }
        dfs(root->left, k);
    }
public:
    int kthLargest(TreeNode* root, int k) {
        dfs(root,k);
        return ans;
    }
};