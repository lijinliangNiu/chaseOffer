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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        while (head != NULL) {
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        //此处一直是原链表尾节点
        ListNode* cur = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return cur;
    }
};