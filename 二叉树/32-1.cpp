class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        vector<int> res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            res.push_back(node->val); 

            if (node->left != nullptr){
                q.push(node->left);
            }

            if (node->right != nullptr){
                q.push(node->right);
            }
        }
        return res;
    }
};