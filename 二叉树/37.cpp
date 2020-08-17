/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root){
        string res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* cur = q.front();
                q.pop();
                if(cur == nullptr){
                    res += "nullptr,";
                }
                else{
                    res += to_string(cur->val) + ",";
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
        }
        return res;
    }

    TreeNode* deserialize(string data) {
        stringstream s(data);
        string str_node;
        queue<TreeNode*> q;
        getline(s, str_node, ',');
        TreeNode* root;
        if(str_node == "nullptr"){
            return nullptr;
        }
        else{
            root = new TreeNode(stoi(str_node));
            q.push(root);
        }
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();                           
            if(cur != nullptr){                                    
                if(getline(s, str_node, ',') && str_node != "nullptr"){
                    TreeNode* l = new TreeNode(stoi(str_node));
                    q.push(l);
                    cur->left = l;
                }                    
                if(getline(s, str_node, ',') && str_node != "nullptr"){   
                    TreeNode* r = new TreeNode(stoi(str_node));
                    q.push(r);
                    cur->right = r;
                }                      
            }
        }   
        return root;
    }
};