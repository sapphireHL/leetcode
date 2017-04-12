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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *pre = dummy, *p = head;
        dummy->next = head;
        while(p && p->next){
            if(p->val == p->next->val){
                while(p && p->next && p->val == p->next->val)
                    p = p->next;
                if(!p->next)
                    pre->next = NULL;
                else{
                    pre->next = p->next;
                    p = p->next;
                }
            }
            else{
                pre = pre->next;
                p = p->next;
            }
        }
        return dummy->next;
    }
};
