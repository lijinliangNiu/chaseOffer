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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(head == NULL || k == 0){
            return NULL;
        }
        ListNode* fast = head;
        for(int i = 0; i < k; i++){
            if(fast == NULL){
                return NULL;
            }
            fast = fast->next;
        }
        while(fast != NULL){
            head = head->next;
            fast = fast->next;
        }
        return head;
    }
};