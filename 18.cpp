/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val == val){
            return head->next;
        }
        for(ListNode* p = head; p != NULL; p = p->next){
            if(p->next->val == val){
                p->next = p->next->next;
                break;
            }
        }
        return head;
    }
};