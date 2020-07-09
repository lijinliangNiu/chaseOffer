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
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        stack<int> sta;
        for(ListNode* p = head; p != NULL; p = p->next){
            sta.push(p->val);
        }
        while(!sta.empty()){
            res.push_back(sta.top());
            sta.pop();
        }
        return res;
    }
};