/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    
    void partialPathSum(TreeNode* root, int sum) {
        if(root == nullptr) {
            return;
        }
        path.push_back(root->val);
        sum -= root->val;
        if(sum == 0 && root->left == nullptr && root->right == nullptr){
            res.push_back(path);
        }
        partialPathSum(root->left, sum);
        partialPathSum(root->right, sum);
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        partialPathSum(root, sum);
        return res;
    }
};