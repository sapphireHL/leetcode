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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0), *pre = dummy, *right = head;
        dummy->next = head;
        show(head);
        int l=0;
        while(right){
            for(int i=0; i<k-1 && right; i++)
                right = right->next;
            if(!right)  
                break;
            //reverse
            ListNode *end = right->next;
            ListNode *pre2 = pre->next, *p = pre->next, *cur = pre->next->next;
            while(cur != end){
                pre2->next = cur->next;
                cur->next = p;
                p = cur;
                cur = pre2->next;
            }
            pre->next = p;
            pre = pre2;
            right = end;
            show(dummy->next);
        }
        return dummy->next;
    }
};
