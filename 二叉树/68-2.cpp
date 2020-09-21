/*若p和q分别分布在root的左右子树，则root为所求
若左子树返回NULL，则说明pq都在右子树，则进入右子树
若右子树返回NULL，则说明pq都在左子树，则进入左子树*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr){
            return nullptr;
        }
        if(root == p || root == q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left != nullptr && right != nullptr){
            return root;
        }
        else if(left == nullptr){
            return right;
        }
        else{
            return left;
        }
    }
};