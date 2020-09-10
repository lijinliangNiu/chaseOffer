//递归
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

//层序遍历
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int layer_num = q.size();
            for(int i = 0; i < layer_num; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left != nullptr) {
                    q.push(node->left);
                }
                if(node->right != nullptr) {
                    q.push(node->right);
                }
            }
            depth++;
        }
        return depth;
    }
};