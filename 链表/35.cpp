/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }
        for(Node* node = head; node != nullptr; node = node->next->next){
            Node* cloned = new Node(node->val, node->next, nullptr);
            node->next = cloned;
        }
        for(Node* node = head; node != nullptr; node = node->next->next){
            if(node->next->random == nullptr && node->random != nullptr){
                node->next->random = node->random->next;
            }
        }
        Node* ori = head;
        Node* cloned = head->next;
        Node* cloned_head = head->next;
        while(ori != nullptr){
            ori->next = cloned->next;
            ori = ori->next;
            if(ori != nullptr){
                cloned->next = ori->next;
                cloned = cloned->next;
            }
        }
        return cloned_head;
    }
};