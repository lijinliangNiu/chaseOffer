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
    unordered_map<int, int> index;

   public:
    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder,
                        int preorder_left, int preorder_right, int inorder_left,
                        int inorder_right) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preorder_left]);

        int inorder_root = index[root->val];
        int left_subtree_size = inorder_root - inorder_left;
        root->left = buildTree(preorder, inorder, preorder_left + 1,
                               preorder_left + left_subtree_size, inorder_left,
                               inorder_root - 1);
        root->right =
            buildTree(preorder, inorder, preorder_left + left_subtree_size + 1,
                      preorder_right, inorder_root + 1, inorder_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < preorder.size(); ++i) {
            index[inorder[i]] = i;
        }
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0,
                         inorder.size() - 1);
    }
};