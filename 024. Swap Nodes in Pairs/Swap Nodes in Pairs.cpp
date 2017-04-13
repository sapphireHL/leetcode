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
    ListNode* swapPairs(ListNode* head) {
        ListNode *p = head, *dummy = new ListNode(0), *pre = NULL;
        dummy->next = head;
        while(p && p->next){
            if(dummy->next == head)
                dummy->next = p->next;
            ListNode *temp = p->next;
            p->next = p->next->next;
            temp->next = p;
            if(pre)
                pre->next = temp;
            pre = p;
            p = p->next;
        }
        return dummy->next;
    }
};
