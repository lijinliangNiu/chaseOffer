class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        vector<vector<int>> res;
        deque<TreeNode*> q;
        q.push_back(root);
        bool is_double = true;

        while (!q.empty()) {
            vector<int> level;
            int level_num = q.size();
            for (int i = 0; i < level_num; i++) {
                TreeNode* node;
                if (is_double) {
                    node = q.front();
                    q.pop_front();
                    if (node->left != nullptr) {
                        q.push_back(node->left);
                    }
                    if (node->right != nullptr) {
                        q.push_back(node->right);
                    }
                } 
                else {
                    node = q.back();
                    q.pop_back();
                    if (node->right != nullptr) {
                        q.push_front(node->right);
                    }
                    if (node->left != nullptr) {
                        q.push_front(node->left);
                    }
                }
                level.push_back(node->val);
            }
            res.push_back(level);
            is_double = !is_double;
        }
        return res;
    }
};