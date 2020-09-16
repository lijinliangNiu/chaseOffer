class Solution {
private:
    int depth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        else{
            return max(depth(root->left), depth(root->right)) + 1;
        }
    }

public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        else{
            return abs(depth(root->left) - depth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        }
    }
};