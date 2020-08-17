/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr) {
            return nullptr;
        }
        Node* head = nullptr, *pre = nullptr;
        helper(root, head, pre);
        head->left = pre;
        pre->right = head;
        return head;
    }
    void helper(Node* root, Node*& head, Node*& pre) {
        if(root == nullptr)  {
            return;
        }
        helper(root->left, head, pre);
        if(head == nullptr) {
            head = root;   // 找到head
        } 
        else {
            pre->right = root;
            root->left = pre;
        }
        pre = root;
        helper(root->right, head, pre);
    }
};