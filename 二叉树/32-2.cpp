class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> level;
            int level_num = q.size();
            for (int i = 0; i < level_num; i ++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left != nullptr) {
                    q.push(node->left);
                }
                if(node->right != nullptr) {
                    q.push(node->right);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};